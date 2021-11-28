#include "BMP/BMPTestFiles.cpp"
#include <string.h>
#include "Log.h"
DEFTEST_UNIT(ImageSupport);


#define TEST_PIXEL(x, y, c) { \
        umm pixel = ((umm)import.data.buffer + import.image.offset_at(Vec2i{x, y})); \
        uint32 buffer = 0; \
        memcpy(&buffer, pixel, import.image.bpp / 8); \
        MFAILIF(buffer != (c)); \
    }


DEFTEST_CASE(LoadBMP, ImageSupport, "BMP Support");
TEST_CASE(LoadBMP) {

    for (int i = 0; i < ARRAY_COUNT(BMP_Image_Test_Files); ++i) {
        Str &path = BMP_Image_Test_Files[i];

        PRINTLN("File: " + path);

        Import import;
        bool result = Importer_Registry.load_file(path, get_system_allocator(), &import);
        if (!result) {
            return MFAILED("Failed to load file");
        }

        uint32 mask_r = PixelFormat::mask_of(import.image.format, 0);
        uint32 mask_g = PixelFormat::mask_of(import.image.format, 1);
        uint32 mask_b = PixelFormat::mask_of(import.image.format, 2);
        uint32 mask_a = PixelFormat::mask_of(import.image.format, 3);

        TEST_PIXEL(0, 0, mask_r);
        TEST_PIXEL(0, 1, mask_g);
        TEST_PIXEL(1, 0, mask_b);
        TEST_PIXEL(1, 1, mask_r | mask_g | mask_b);
    }

    return MPASSED();
}