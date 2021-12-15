#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "opencv2/opencv.hpp"



int main() {
    cv::VideoCapture cap;
    for(int i=5;i>=0;--i) if(cap.open(i)) break;
    if(!cap.isOpened()) {
        std::cout << "Failed to open video stream\n";
        return 1;
    } else {
        cv::Mat frame;
        cv::namedWindow("display", cv::WINDOW_AUTOSIZE);
        
        auto s = cv::getWindowImageRect("display");
        std::cout << "ImageSize: " << s.width << " " << s.height << "\n";

        do {
            if(!cv::getWindowProperty("display", cv::WindowPropertyFlags::WND_PROP_VISIBLE)) break;

            if(!cap.read(frame)){
                std::cout << "Failed to read frame\n";
                break;
            }

            cv::imshow("display", frame);
            if(cv::waitKeyEx(1) == 32){ // spacebar to capture
                std::vector<uchar> buf;
                cv::imencode(".png", frame, buf, std::vector<int>());
                std::string data(buf.begin(), buf.end());

                std::ofstream file("out.png", std::ios::binary);
                file.write(data.data(), data.size());
                file.close();
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); // sleep to prevent lots of captures
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        } while(1);

        cv::destroyAllWindows();
    }
    cap.release();

    return 0;
}