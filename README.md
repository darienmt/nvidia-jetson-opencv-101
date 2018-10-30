# NVIDIA Jetson TX1 OpenCV 101 Tutorials

![Hello!](./images/hello.png)

In this repo, you will found the code from the [OpenCV 101 tutorials](https://developer.nvidia.com/embedded/learn/tutorials). The tutorials a bit old and there are a couple of things that need to be fixed to be implemented with OpenCV 3.3.1.



## Dev environment

- [NVIDIA Jetson TX1 Developer Kit SE](https://developer.nvidia.com/embedded/buy/jetson-tx1-devkit)
- [JetPack 3.3](https://developer.nvidia.com/embedded/jetpack)
- OpenCV 3.3.1
- CMake 3.5.1
- Midnight Commander

## Tutorials

- [0-cv-hello](./0-cv-hello):  Episode 0 - [Introduction to OpenCV](https://www.youtube.com/watch?v=gvmP0WRVUxI): Learn to write your first ‘Hello World’ program on Jetson with OpenCV. You’ll learn a simple compilation pipeline with Midnight Commander, cmake, and OpenCV4Tegra’s mat library, as you build for the first time.

- [1-cv-mat](./1-cv-mat): Episode 1 - [CV Mat Container](https://www.youtube.com/watch?v=lQfWANnqmps) Learn to work with mat, OpenCV’s primary container. You’ll learn memory allocation for a basic image matrix, then test a CUDA image copy with sample grayscale and color images.

- [2-cv-io](./2-cv-io): Episode 2: [Multimedia I/O](https://www.youtube.com/watch?v=PEaNXO5SKsE)
Learn to manipulate images from various sources: JPG and PNG files, and USB webcams. Run standard filters such as Sobel, then learn to display and output back to file. Implement a rudimentary video playback mechanism for processing and saving sequential frames.

- [3-cv-basic](./3-cv-basic): Episode 3: [Basic Operations](https://www.youtube.com/watch?v=7bgjQh_Fasg)
Start with an app that displays an image as a Mat object, then resize, rotate it or detect “canny” edges, then display the result. Then, to ignore the high-frequency edges of the image’s feather, blur the image and then run the edge detector again. With higher window sizes, the feather’s edges disappear, leaving behind only the more significant edges present in the input image.

- [4-cv-flow](./4-cv-flow): Episode 4: [Feature Detection and Optical Flow](https://www.youtube.com/watch?v=WjtJmb9dROQ)
Take an input MP4 video file (footage from a vehicle crossing the Golden Gate Bridge) and detect corners in a series of sequential frames, then draw small marker circles around the identified features. Watch as these demarcated features are tracked from frame to frame. Then, color the feature markers depending on how far they move frame to frame. This simplistic analysis allows points distant from the camera—which move less—to be demarcated as such.


