#include <opencv2/features2d.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <numeric>

void step1(cv::VideoCapture input);
void step2(cv::VideoCapture input);

int main() 
{
    cv::VideoCapture input("cars.mp4");
    // step1(input);
    step2(input);
}

void step1(cv::VideoCapture input)
{

    cv::Mat img;
    
    // Step 1 : Detect features on a video image

    // This doesn't work with OpenCV 3.3.1
    // cv::OrbFeatureDetector detector;

    // Follow code in:
    //  https://devtalk.nvidia.com/default/topic/1024551/jetson-tx2/episode-4-feature-detection-and-optical-flow-problem-/post/5211987/#5211987
    
    cv::Mat desc;
    cv::Ptr<cv::ORB> detector = cv::ORB::create();
        
    std::vector<cv::KeyPoint> keypoints;

    cv::VideoWriter output(
		"cars_features.avi",
		CV_FOURCC('X', 'V', 'I', 'D'),
		30,
		cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
		    input.get(CV_CAP_PROP_FRAME_HEIGHT)));

    for(;;) 
    {
	if (!input.read(img)) {
	    break;
	}
	
	detector->detect(img, keypoints, desc);

	for( size_t i = 0; i < keypoints.size(); i++ ) {
	    cv::circle(img, keypoints[i].pt, 2,
		cv::Scalar(0, 0, 255), 1);
	}

	output.write(img);

	cv::imshow("img", img);
	
	char c = cv::waitKey(20);
	
	if ( c == 27 ) { // 27 is ESC code
	    break;
	}
    }
    
}

void step2(cv::VideoCapture input)
{
    // Step 8 : Optical-flow

    cv::Mat img, img_prev;
    std::vector<cv::Point2f> points, points_prev;
    std::vector<uchar> status;
    std::vector<float> errors;

    cv::Mat desc;

    cv::Ptr<cv::ORB> detector = cv::ORB::create();
    std::vector<cv::KeyPoint> keypoints;

    cv::VideoWriter output(
		"cars_flow_2.avi",
		CV_FOURCC('X', 'V', 'I', 'D'),
		30,
		cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
		    input.get(CV_CAP_PROP_FRAME_HEIGHT)));
    
    input.read(img);
    detector->detect(img, keypoints, desc);
    cv::KeyPoint::convert(keypoints, points);
    img.copyTo(img_prev);
    points_prev = points;

    for(;;) 
    {
	if (!input.read(img)) {
	    break;
	}

	cv::calcOpticalFlowPyrLK(
	    img_prev, img,
	    points_prev, points,
	    status, errors);

	img.copyTo(img_prev);
	

	for( size_t i = 0; i < points.size(); i++ ) {
	    cv::circle(img, points[i], 3,
		cv::Scalar(0, 0, cv::norm(points_prev[i] - points[i]) * 20), 3);
	}
	
	std::stringstream pointLabel;
	
	pointLabel << "Points count : " << std::accumulate(status.begin(), status.end(), 0);
	cv::putText( img,
		pointLabel.str(),
		cv::Point(10, 30),
		cv::FONT_HERSHEY_DUPLEX,
		1.0,
		CV_RGB(255, 0, 0),
		2);

	points_prev = points;
	
	output.write(img);

	cv::imshow("img", img);
	
	char c = cv::waitKey(20);
	
	if ( c == 27 ) { // 27 is ESC code
	    break;
	}
    }
    
}

