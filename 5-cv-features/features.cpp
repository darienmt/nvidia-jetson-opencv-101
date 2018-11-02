#include <opencv2/features2d.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>

int main() 
{
    cv::VideoCapture input("cars.mp4");

    cv::Mat img;
    // Source:
    // https://devtalk.nvidia.com/default/topic/1026243/jetson-tx1/orbfeaturedetector-problem-when-using-opencv/
    //
    // Because the code in the video doesn't work.

    cv::Mat desc;
    cv::Ptr<cv::ORB> detector = cv::ORB::create();
    cv::Ptr<cv::ORB> extractor = cv::ORB::create();
        
    std::vector<cv::KeyPoint> keypoints, car_keypoints;
    cv::Mat img_descriptors, car_descriptors;

    input.read(img);
    cv::Mat car;
    img(cv::Rect(994, 405, 240, 110)).copyTo(car);
    detector->detect(car, car_keypoints);
    extractor->compute(car, car_keypoints, car_descriptors);
    drawKeypoints(car, car_keypoints, car);

    for(;;) 
    {
        if (!input.read(img)) {
            break;
        }
        
        detector->detect(img, keypoints);
        extractor->compute(img, keypoints, img_descriptors);
	    drawKeypoints(img, keypoints, img);

        cv::BFMatcher matcher;
        std::vector<cv::DMatch> matches;
        matcher.match(car_descriptors, img_descriptors, matches);

        std::vector<cv::Point2f> car_points, img_points;
        for (size_t i = 0; i < matches.size(); i++){
            car_points.push_back(car_keypoints[matches[i].queryIdx].pt);
            img_points.push_back(keypoints[matches[i].trainIdx].pt);
        }

        cv::Matx33f H = cv::findHomography(car_points, img_points, CV_RANSAC);
        
        std::vector<cv::Point> car_border, img_border;
        car_border.push_back(cv::Point(0, 0));
        car_border.push_back(cv::Point(0, car.rows));
        car_border.push_back(cv::Point(car.cols, car.rows));
        car_border.push_back(cv::Point(car.cols, 0));

        for (size_t i = 0; i < car_border.size(); i++) {
            cv::Vec3f p = H * cv::Vec3f(car_border[i].x, car_border[i].y, 1);

            img_border.push_back(cv::Point(p[0] / p[2], p[1] / p[2] ));
        }

        cv::polylines(img, img_border, true, CV_RGB(255, 255, 255),3);
        
        cv::Mat img_matches;
        cv::drawMatches(car, car_keypoints, img, keypoints, matches, img_matches);

        cv::imshow("img_matches", img_matches);
        
        char c = cv::waitKey(20);
        
        if ( c == 27 ) { // 27 is ESC code
            break;
        }
    }
}