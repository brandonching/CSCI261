#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H
void print_file_options();
void print_operation_options();
int get_user_input(int minValue, int maxValue);
bool open_files(std::ifstream& inputImage, std::ofstream& outputImage,
                int fileOption, int operationOption);
bool read_header_information(std::ifstream& inputImage, int& width, int& height,
                             int& maxValue);
void write_header_information(std::ofstream& outputImage, int width, int height,
                              int maxValue);
void read_and_write_modified_pixels(std::ifstream& inputImage,
                                    std::ofstream& outputImage,
                                    int operationOption, int width, int height,
                                    int maxValue);
#endif