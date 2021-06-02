#include <aws/lambda-runtime/runtime.h>
#include <aws/logging/logging.h>

#include <unordered_map>
#include <string>
#include <functional>

using namespace aws::lambda_runtime;

constexpr unsigned int AWSLOGO_PNG_LEN = 1451;
extern unsigned char awslogo_png[AWSLOGO_PNG_LEN]; // NOLINT

invocation_response echo_success(invocation_request const& request)
{
    return invocation_response::success(request.payload, "application/json");
}

invocation_response echo_failure(invocation_request const& /*request*/)
{
    return invocation_response::failure("Test error message", "TestErrorType");
}

invocation_response binary_response(invocation_request const& /*request*/)
{
    const std::string png((char*)awslogo_png, AWSLOGO_PNG_LEN);
    return invocation_response::success(png, "image/png");
}

int main(int argc, char* argv[])
{
    std::unordered_map<std::string, std::function<invocation_response(invocation_request const&)>> handlers;
    handlers.emplace("echo_success", echo_success);
    handlers.emplace("echo_failure", echo_failure);
    handlers.emplace("binary_response", binary_response);

    if (argc < 2) {
        aws::logging::log_error("lambda_fun", "Missing handler argument. Exiting.");
        return -1;
    }

    auto it = handlers.find(argv[1]);
    if (it == handlers.end()) {
        aws::logging::log_error("lambda_fun", "Handler %s not found. Exiting.", argv[1]);
        return -2;
    }
    run_handler(it->second);
    return 0;
}

/* clang-format off */
unsigned char awslogo_png[] = { // NOLINT
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, // NOLINT
    0x18, 0x00, 0x00, 0x00, 0x0e, 0x08, 0x06, 0x00, 0x00, 0x00, 0x35, 0xf8, 0xdc, 0x7e, 0x00, 0x00, 0x00, 0x04, 0x67, // NOLINT
    0x41, 0x4d, 0x41, 0x00, 0x00, 0xb1, 0x8f, 0x0b, 0xfc, 0x61, 0x05, 0x00, 0x00, 0x00, 0x20, 0x63, 0x48, 0x52, 0x4d, // NOLINT
    0x00, 0x00, 0x7a, 0x26, 0x00, 0x00, 0x80, 0x84, 0x00, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x80, 0xe8, 0x00, 0x00, 0x75, // NOLINT
    0x30, 0x00, 0x00, 0xea, 0x60, 0x00, 0x00, 0x3a, 0x98, 0x00, 0x00, 0x17, 0x70, 0x9c, 0xba, 0x51, 0x3c, 0x00, 0x00, // NOLINT
    0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0b, 0x13, 0x00, 0x00, 0x0b, 0x13, 0x01, 0x00, 0x9a, 0x9c, 0x18, // NOLINT
    0x00, 0x00, 0x01, 0x59, 0x69, 0x54, 0x58, 0x74, 0x58, 0x4d, 0x4c, 0x3a, 0x63, 0x6f, 0x6d, 0x2e, 0x61, 0x64, 0x6f, // NOLINT
    0x62, 0x65, 0x2e, 0x78, 0x6d, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x78, 0x3a, 0x78, 0x6d, 0x70, 0x6d, 0x65, // NOLINT
    0x74, 0x61, 0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x78, 0x3d, 0x22, 0x61, 0x64, 0x6f, 0x62, 0x65, 0x3a, 0x6e, // NOLINT
    0x73, 0x3a, 0x6d, 0x65, 0x74, 0x61, 0x2f, 0x22, 0x20, 0x78, 0x3a, 0x78, 0x6d, 0x70, 0x74, 0x6b, 0x3d, 0x22, 0x58, // NOLINT
    0x4d, 0x50, 0x20, 0x43, 0x6f, 0x72, 0x65, 0x20, 0x35, 0x2e, 0x34, 0x2e, 0x30, 0x22, 0x3e, 0x0a, 0x20, 0x20, 0x20, // NOLINT
    0x3c, 0x72, 0x64, 0x66, 0x3a, 0x52, 0x44, 0x46, 0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x72, 0x64, 0x66, 0x3d, // NOLINT
    0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x77, 0x33, 0x2e, 0x6f, 0x72, 0x67, 0x2f, // NOLINT
    0x31, 0x39, 0x39, 0x39, 0x2f, 0x30, 0x32, 0x2f, 0x32, 0x32, 0x2d, 0x72, 0x64, 0x66, 0x2d, 0x73, 0x79, 0x6e, 0x74, // NOLINT
    0x61, 0x78, 0x2d, 0x6e, 0x73, 0x23, 0x22, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x72, 0x64, 0x66, // NOLINT
    0x3a, 0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x72, 0x64, 0x66, 0x3a, 0x61, 0x62, // NOLINT
    0x6f, 0x75, 0x74, 0x3d, 0x22, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, // NOLINT
    0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x74, 0x69, 0x66, 0x66, 0x3d, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, // NOLINT
    0x6e, 0x73, 0x2e, 0x61, 0x64, 0x6f, 0x62, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x74, 0x69, 0x66, 0x66, 0x2f, 0x31, // NOLINT
    0x2e, 0x30, 0x2f, 0x22, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x74, 0x69, 0x66, // NOLINT
    0x66, 0x3a, 0x4f, 0x72, 0x69, 0x65, 0x6e, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x31, 0x3c, 0x2f, 0x74, 0x69, // NOLINT
    0x66, 0x66, 0x3a, 0x4f, 0x72, 0x69, 0x65, 0x6e, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x0a, 0x20, 0x20, 0x20, // NOLINT
    0x20, 0x20, 0x20, 0x3c, 0x2f, 0x72, 0x64, 0x66, 0x3a, 0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6f, // NOLINT
    0x6e, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x3c, 0x2f, 0x72, 0x64, 0x66, 0x3a, 0x52, 0x44, 0x46, 0x3e, 0x0a, 0x3c, 0x2f, // NOLINT
    0x78, 0x3a, 0x78, 0x6d, 0x70, 0x6d, 0x65, 0x74, 0x61, 0x3e, 0x0a, 0x4c, 0xc2, 0x27, 0x59, 0x00, 0x00, 0x03, 0xbc, // NOLINT
    0x49, 0x44, 0x41, 0x54, 0x38, 0x11, 0x65, 0x54, 0x6f, 0x6c, 0x53, 0x55, 0x14, 0x3f, 0xe7, 0xbe, 0xd7, 0x75, 0xf2, // NOLINT
    0x18, 0x1a, 0x24, 0xc4, 0xc1, 0x20, 0x0a, 0x6b, 0x27, 0x1b, 0xa3, 0x85, 0xa4, 0x92, 0x29, 0x5d, 0xbb, 0x25, 0x82, // NOLINT
    0xc6, 0x48, 0x0c, 0x61, 0x43, 0x0d, 0x4a, 0x98, 0x91, 0x19, 0xa3, 0x7e, 0x22, 0x41, 0x09, 0xc9, 0xe0, 0x83, 0x06, // NOLINT
    0x35, 0x31, 0x46, 0x8c, 0xc1, 0x05, 0x25, 0xc1, 0xc8, 0x97, 0xc5, 0xc4, 0x38, 0xd0, 0x84, 0x60, 0x52, 0xba, 0x2d, // NOLINT
    0x68, 0xd0, 0x6c, 0x65, 0x56, 0xb1, 0xab, 0x3a, 0x70, 0x09, 0x68, 0x84, 0x0f, 0xba, 0xd5, 0xba, 0xbe, 0x77, 0x8f, // NOLINT
    0xbf, 0x7b, 0xcb, 0x32, 0xff, 0x9c, 0xe6, 0xdc, 0x73, 0xcf, 0xb9, 0xbf, 0xf3, 0xf7, 0xde, 0x57, 0x26, 0x50, 0x74, // NOLINT
    0x7d, 0x47, 0x4c, 0x74, 0xf0, 0x2a, 0xb6, 0x2b, 0x88, 0x69, 0x21, 0x6b, 0x1a, 0xd5, 0x25, 0x6f, 0x07, 0x79, 0x33, // NOLINT
    0x29, 0x26, 0xea, 0xad, 0xf1, 0xd5, 0xae, 0x7c, 0x3e, 0x33, 0x1d, 0x8d, 0xa7, 0x1f, 0x21, 0x09, 0x7a, 0x1d, 0x97, // NOLINT
    0x7a, 0xbe, 0xfb, 0x7a, 0xe8, 0x6a, 0x34, 0x9e, 0x4a, 0x88, 0x48, 0x9f, 0x2a, 0x07, 0x8f, 0x05, 0x61, 0xa7, 0x43, // NOLINT
    0x31, 0xbd, 0x6e, 0xe2, 0x09, 0xd1, 0x34, 0x2b, 0xb5, 0xaf, 0x30, 0x9a, 0x39, 0xab, 0xac, 0x41, 0xcb, 0x0a, 0x04, // NOLINT
    0x1a, 0x55, 0x4a, 0xed, 0x12, 0x96, 0x27, 0x85, 0x69, 0x33, 0x7b, 0x33, 0x6f, 0x6a, 0xd2, 0x93, 0x8e, 0x1b, 0xda, // NOLINT
    0x56, 0x76, 0x25, 0x61, 0x71, 0xa2, 0x77, 0x86, 0x6a, 0xbd, 0x07, 0xfc, 0x0a, 0xdd, 0x5b, 0x0d, 0xa4, 0x77, 0x43, // NOLINT
    0xc6, 0xb4, 0xe7, 0x34, 0x30, 0xd3, 0xc7, 0x9a, 0xf8, 0xa8, 0x62, 0xb5, 0x85, 0x99, 0xdf, 0xd5, 0x5a, 0xdb, 0xd8, // NOLINT
    0x8a, 0xba, 0xba, 0x9c, 0x89, 0x5c, 0xe6, 0x54, 0x21, 0x97, 0x7d, 0xa9, 0xfe, 0x56, 0x1a, 0x2b, 0x8e, 0x0e, 0x9d, // NOLINT
    0x43, 0x09, 0x6f, 0xa0, 0x8a, 0xce, 0x1f, 0x73, 0xc3, 0x85, 0xc0, 0xaf, 0x14, 0x1d, 0xd2, 0x69, 0x13, 0x10, 0xb4, // NOLINT
    0x74, 0xb6, 0x5c, 0xba, 0x40, 0xc4, 0x49, 0xab, 0x09, 0xa7, 0x44, 0xe8, 0x98, 0x2f, 0x7e, 0xc9, 0x71, 0x5c, 0x56, // NOLINT
    0x22, 0x37, 0x2e, 0x8d, 0x65, 0x26, 0x0b, 0x63, 0xe7, 0xfa, 0x8b, 0xb9, 0xec, 0x19, 0x13, 0x1b, 0x85, 0x63, 0x44, // NOLINT
    0xad, 0x9b, 0x56, 0x91, 0x52, 0xc7, 0x10, 0xb4, 0x01, 0xea, 0x15, 0xc8, 0x16, 0x1c, 0x5c, 0x9d, 0xc8, 0x65, 0x37, // NOLINT
    0x44, 0xe2, 0xc9, 0x77, 0x88, 0x54, 0x84, 0x39, 0xd8, 0x2b, 0x5a, 0x1d, 0x11, 0x92, 0x7e, 0x26, 0xde, 0xa3, 0xc5, // NOLINT
    0xdf, 0xae, 0xd8, 0x2d, 0x90, 0xa6, 0xad, 0x13, 0xe3, 0xd9, 0x6c, 0x34, 0x96, 0x3c, 0x24, 0xc4, 0x07, 0xe0, 0xff, // NOLINT
    0x3b, 0xf8, 0x74, 0xc5, 0x57, 0x7b, 0x27, 0xf3, 0x99, 0x6b, 0xb6, 0x0d, 0xad, 0xd4, 0x09, 0x4d, 0xb4, 0x44, 0x09, // NOLINT
    0x6d, 0x91, 0x19, 0xef, 0x21, 0x62, 0x3e, 0x05, 0x50, 0x18, 0x4c, 0x1c, 0xa8, 0x41, 0x12, 0x69, 0xd0, 0xe2, 0xec, // NOLINT
    0x40, 0xe0, 0xcb, 0x61, 0xdf, 0xff, 0x14, 0x23, 0x58, 0xc0, 0xec, 0xf6, 0xe0, 0xf8, 0x67, 0xf9, 0xd3, 0xfb, 0xd2, // NOLINT
    0xe0, 0x0a, 0xb9, 0xa1, 0x3e, 0xdc, 0xd5, 0x72, 0x8c, 0xf7, 0x39, 0xa8, 0xf7, 0x87, 0x42, 0xf2, 0x81, 0xb1, 0xdb, // NOLINT
    0x04, 0xa8, 0x76, 0x0d, 0x78, 0xe4, 0xfb, 0x8b, 0xd9, 0x9f, 0x8a, 0xc5, 0xcf, 0xfe, 0x82, 0x71, 0x3d, 0xba, 0x58, // NOLINT
    0x6c, 0x00, 0x21, 0xbd, 0xf4, 0x73, 0x88, 0x32, 0x8b, 0xec, 0x43, 0xf5, 0xc3, 0xf9, 0xfc, 0xf9, 0x1b, 0xb8, 0xd8, // NOLINT
    0xeb, 0xc0, 0xbf, 0x0c, 0x3e, 0x6d, 0xf0, 0xd1, 0x58, 0xe7, 0xf2, 0xa6, 0x75, 0xed, 0x77, 0xe1, 0x21, 0x5c, 0x2b, // NOLINT
    0x8e, 0x65, 0x3f, 0x0c, 0x84, 0x4e, 0x6a, 0x2d, 0xeb, 0x8c, 0xbf, 0x6b, 0x16, 0x12, 0x3e, 0x8c, 0x54, 0xaf, 0x45, // NOLINT
    0x62, 0xed, 0x1b, 0xf0, 0x8a, 0xca, 0x98, 0xeb, 0x38, 0x9c, 0x17, 0x47, 0x5b, 0xd3, 0x77, 0xe7, 0xc7, 0x07, 0x2e, // NOLINT
    0xc1, 0x9e, 0x55, 0xca, 0x89, 0xfb, 0x81, 0x8c, 0x54, 0xf1, 0x74, 0xc1, 0x09, 0x85, 0x36, 0x57, 0x82, 0xca, 0x27, // NOLINT
    0x55, 0xf7, 0xa0, 0x19, 0x05, 0x1d, 0x8f, 0xc4, 0x92, 0x53, 0x0b, 0x1c, 0xf6, 0x6a, 0x58, 0x56, 0xdf, 0x1e, 0xa6, // NOLINT
    0x9e, 0x1f, 0x2c, 0xf8, 0xe6, 0x92, 0x48, 0xa4, 0x12, 0x2b, 0xd7, 0x26, 0x77, 0x9a, 0x4a, 0x8c, 0xe9, 0xce, 0x96, // NOLINT
    0xf4, 0x1d, 0x10, 0xb6, 0xc3, 0xa6, 0xa6, 0xfb, 0xea, 0x1a, 0xd7, 0x76, 0xae, 0x9e, 0xd3, 0x1b, 0x1b, 0x37, 0x2e, // NOLINT
    0x5a, 0x15, 0x6f, 0x8f, 0x40, 0x47, 0x1d, 0x55, 0x5a, 0x03, 0xbd, 0xa1, 0xb5, 0xfd, 0x71, 0xa2, 0x8e, 0x6d, 0x44, // NOLINT
    0x4f, 0x78, 0x73, 0x76, 0x46, 0x66, 0xbc, 0x30, 0xf3, 0x74, 0xe7, 0xe9, 0xe0, 0x41, 0x52, 0x60, 0x5c, 0x8b, 0x25, // NOLINT
    0x13, 0xe4, 0x9f, 0xe7, 0xff, 0xd5, 0x6f, 0xc2, 0xaa, 0x42, 0xbe, 0xa2, 0x7a, 0x1a, 0xa7, 0xb6, 0xa0, 0x1c, 0xf2, // NOLINT
    0x1c, 0xae, 0x7c, 0xc1, 0x72, 0x94, 0x9e, 0xc5, 0xd1, 0x34, 0x3f, 0x43, 0x27, 0xe6, 0x90, 0x82, 0x04, 0xdf, 0x52, // NOLINT
    0x8b, 0xdb, 0x4c, 0x79, 0x93, 0xc4, 0x26, 0xea, 0xce, 0x77, 0xf1, 0xc0, 0xc0, 0x40, 0x60, 0x30, 0x18, 0x21, 0x1f, // NOLINT
    0xea, 0x48, 0x3b, 0x7d, 0xe9, 0x8c, 0xa6, 0x66, 0xdb, 0x85, 0xc3, 0xdd, 0x34, 0x5b, 0x7a, 0xbb, 0xae, 0x2d, 0xe4, // NOLINT
    0x96, 0xb7, 0x2b, 0x0a, 0x1c, 0xc5, 0xfa, 0x61, 0x40, 0x67, 0x58, 0xde, 0xa2, 0x45, 0x78, 0x2f, 0xaf, 0x40, 0xd9, // NOLINT
    0x08, 0x36, 0x37, 0x7f, 0x92, 0x7b, 0xe9, 0x37, 0xc8, 0xff, 0x91, 0x49, 0x6c, 0x8d, 0x7d, 0xb8, 0x35, 0xfe, 0x57, // NOLINT
    0x57, 0xd6, 0x8c, 0x58, 0x61, 0xaa, 0xa5, 0x6e, 0x94, 0x74, 0x19, 0x86, 0x85, 0xe0, 0x17, 0x4d, 0xbb, 0x96, 0xa4, // NOLINT
    0x9f, 0xb6, 0xc2, 0xc5, 0x7c, 0xea, 0x66, 0xd6, 0xc3, 0xe0, 0x41, 0xd4, 0x76, 0x1e, 0xcf, 0x60, 0x82, 0xae, 0xd0, // NOLINT
    0x75, 0x9e, 0x1f, 0x99, 0xc5, 0x9b, 0x45, 0xde, 0xa3, 0x3a, 0x0a, 0x68, 0x25, 0x02, 0xde, 0x03, 0xec, 0x83, 0x30, // NOLINT
    0xb5, 0x21, 0xc6, 0x14, 0xe4, 0x53, 0x28, 0xe5, 0x79, 0xec, 0xbf, 0x61, 0x5b, 0x15, 0xda, 0x44, 0x8b, 0xd5, 0xf6, // NOLINT
    0xfb, 0xe9, 0x51, 0x1c, 0xbc, 0x80, 0xc0, 0x6d, 0xf6, 0x4b, 0x28, 0x99, 0x48, 0xf4, 0x0b, 0xd6, 0x5f, 0xc1, 0x7f, // NOLINT
    0x80, 0xcd, 0xc8, 0x6e, 0x01, 0x2f, 0x01, 0xd7, 0x53, 0x0d, 0x7e, 0xb3, 0xd6, 0x36, 0x84, 0x24, 0x47, 0x78, 0x0f, // NOLINT
    0x7d, 0x84, 0x98, 0x2e, 0x2d, 0xa3, 0xfd, 0x74, 0x1b, 0x1d, 0x9e, 0xef, 0x00, 0x46, 0x54, 0xe9, 0xc3, 0xc9, 0x92, // NOLINT
    0xbc, 0x8f, 0x3f, 0xbe, 0x59, 0x4a, 0xc1, 0x69, 0x13, 0x0c, 0x2d, 0x48, 0xb2, 0x0c, 0x7b, 0xd3, 0xb6, 0xb9, 0xf0, // NOLINT
    0x69, 0xf0, 0x14, 0x76, 0x17, 0x21, 0x47, 0xc8, 0xa1, 0x0c, 0x3f, 0x6d, 0x8b, 0x80, 0x0a, 0xc0, 0x71, 0xaa, 0xe5, // NOLINT
    0xdd, 0x54, 0x36, 0xfb, 0xbf, 0x01, 0x02, 0x9d, 0x70, 0x74, 0xcd, 0x2a, 0x03, 0x15, 0x00, 0x00, 0x00, 0x00, 0x49, // NOLINT
    0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82}; // NOLINT
/* clang-format on */
