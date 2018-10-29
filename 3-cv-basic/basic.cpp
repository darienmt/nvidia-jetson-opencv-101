#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() 
{
    cv::Mat img = cv::imread("lena.jpg");

    cv::imshow("img", img);

    // Step 1: Resize the image

    cv::Mat img_processed;
    cv::resize(img, img_processed, cv::Size(img.cols / 2, img.rows / 2));

    cv::imshow("img_processed", img_processed);

    // Step 2: Rotate the image

    cv::Mat R = cv::getRotationMatrix2D(cv::Point(img.cols / 2, img.rows / 2), 45, 1);
    
    cv::warpAffine(img, img_processed, R, img.size());

    cv::imshow("img_rot", img_processed);

    // Step 3: Using Canny for edge detection

    // cv::Canny(img, img_processed, 100, 150);
    //cv::Canny(img, img_processed, 200, 300);

    //cv::imshow("img_edges", img_processed);

    //cv::waitKey();

    // Step 4: Bluring the image before applying Canny
    for (int i = 1; i < 20; i+=2)
    {
	cv::Mat img_blurred;
	cv::blur(img, img_blurred, cv::Size(i, i));
	
	cv::Canny(img_blurred, img_processed, 100, 150);
	
	cv::imshow("img", img);
	cv::imshow("img_blurred", img_blurred);
	cv::imshow("img_processed", img_processed);
	cv::waitKey();
    }
}