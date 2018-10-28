#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() 
{
    cv::Mat img = cv::imread("lena.jpg");
    
    
    
    // Step 1: just showing the image
    // cv::imshow("img", img);

    // Step 2 and 3: Sobel lena and save it to disk.
    // cv::Mat dst;
    // cv::Sobel(img, dst, CV_32F, 1, 1);
    
    //cv::imshow("img", dst / 256 );
    
    //cv::imwrite("lena_sobel.png", dst);
    //cv::waitKey();

    // Step 4: Video processing and saving a video

    cv::Mat dst;

    cv::VideoCapture input("cars.mp4");

    cv::VideoWriter output(
	"car_sobel.avi",
	CV_FOURCC('X', 'V', 'I', 'D'),
	30,
	cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
		 input.get(CV_CAP_PROP_FRAME_HEIGHT)));

    for(;;)
    {
	if (!input.read(img))
	    break;
	
	cv::Sobel(img, dst, CV_8U, 1, 1);

	output.write(dst);

	cv::imshow("img", dst);
	char c = cv::waitKey(30);

	if (c == ' ')
	    break;
    }
}