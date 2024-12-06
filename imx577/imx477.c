#include "imx477.h"

I2CReg sensor_init[] = {
    {0x0111, 0xFF}, // Register 0x01, Value 0xFF
    {0x0211, 0x80}, // Register 0x02, Value 0x80
    {0x0011, 0x00},  // End marker
    {0x0501, 0x01},  // End marker
    {0x0610, 0x10}  // End marker
};
I2CReg imx477_sensor_base_configuration_settings[] = {
   {IMX477_MODE_SEL, 0x00},       // IMX577 compatible
    {IMX477_EXCK_FREQ_15_8, 0x18}, // IMX577 compatible
    {IMX477_EXCK_FREQ_7_0, 0x00},  // IMX577 compatible
 
    {0x3C7E, 0x01},
    {0x3C7F, 0x02},
 
    {IMX477_FRAME_BLANKSTOP_CL, 0x01}, // IMX577 compatible
    {IMX477_PSMODE_SEL, IMX477_PSMODE_SEL_LP11},
    // {0xE07A, 0x01}, // ? - IMX477
    {IMX477_DPHY_CTRL, 0x02}, // IMX577 compatible
    // {0x4AE9, 0x18}, // ? - IMX477
    // {0x4AEA, 0x08}, // ? - IMX477
    // {0xF61C, 0x04}, // ? - IMX477
    // {0xF61E, 0x04}, // ? - IMX477
    // {0x4AE9, 0x21}, // ? - IMX477
    // {0x4AEA, 0x80}, // ? - IMX477
    {IMX477_PD_AREA_WIDTH_12_8, 0x1F},  // Doesn't apply for IMX577
    {IMX477_PD_AREA_WIDTH_7_0, 0xFF},   // Doesn't apply for IMX577
    {IMX477_PD_AREA_HEIGHT_12_8, 0x1F}, // Doesn't apply for IMX577
    {IMX477_PD_AREA_HEIGHT_7_0, 0xFF},  // Doesn't apply for IMX577
    // {0x55D4, 0x00}, // ? - IMX477
    // {0x55D5, 0x00}, // ? - IMX477
    // {0x55D6, 0x07}, // ? - IMX477
    // {0x55D7, 0xFF}, // ? - IMX477
    // {0x55E8, 0x07}, // ? - IMX477
    // {0x55E9, 0xFF}, // ? - IMX477
    // {0x55EA, 0x00}, // ? - IMX477
    // {0x55EB, 0x00}, // ? - IMX477
    // {0x574C, 0x07}, // ? - IMX477
    // {0x574D, 0xFF}, // ? - IMX477
    // {0x574E, 0x00}, // ? - IMX477
    // {0x574F, 0x00}, // ? - IMX477
    // {0x5754, 0x00}, // ? - IMX477
    // {0x5755, 0x00}, // ? - IMX477
    // {0x5756, 0x07}, // ? - IMX477
    // {0x5757, 0xFF}, // ? - IMX477
    // {0x5973, 0x04}, // ? - IMX477
    // {0x5974, 0x01}, // ? - IMX477
    // {0x5D13, 0xC3}, // ? - IMX477
    // {0x5D14, 0x58}, // ? - IMX477
    // {0x5D15, 0xA3}, // ? - IMX477
    // {0x5D16, 0x1D}, // ? - IMX477
    // {0x5D17, 0x65}, // ? - IMX477
    // {0x5D18, 0x8C}, // ? - IMX477
    // {0x5D1A, 0x06}, // ? - IMX477
    // {0x5D1B, 0xA9}, // ? - IMX477
    // {0x5D1C, 0x45}, // ? - IMX477
    // {0x5D1D, 0x3A}, // ? - IMX477
    // {0x5D1E, 0xAB}, // ? - IMX477
    // {0x5D1F, 0x15}, // ? - IMX477
    // {0x5D21, 0x0E}, // ? - IMX477
    // {0x5D22, 0x52}, // ? - IMX477
    // {0x5D23, 0xAA}, // ? - IMX477
    // {0x5D24, 0x7D}, // ? - IMX477
    // {0x5D25, 0x57}, // ? - IMX477
    // {0x5D26, 0xA8}, // ? - IMX477
    // {0x5D37, 0x5A}, // ? - IMX477
    // {0x5D38, 0x5A}, // ? - IMX477
    // {0x5D77, 0x7F}, // ? - IMX477
    // {0x7B75, 0x0E}, // ? - IMX477
    // {0x7B76, 0x0B}, // ? - IMX477
    // {0x7B77, 0x08}, // ? - IMX477
    // {0x7B78, 0x0A}, // ? - IMX477
    // {0x7B79, 0x47}, // ? - IMX477
    // {0x7B7C, 0x00}, // ? - IMX477
    // {0x7B7D, 0x00}, // ? - IMX477
    // {0x8D1F, 0x00}, // ? - IMX477
    // {0x8D27, 0x00}, // ? - IMX477
    // {0x9004, 0x03}, // ? - IMX477
    // {0x9200, 0x50}, // ? - IMX477
    // {0x9201, 0x6C}, // ? - IMX477
    // {0x9202, 0x71}, // ? - IMX477
    // {0x9203, 0x00}, // ? - IMX477
    // {0x9204, 0x71}, // ? - IMX477
    // {0x9205, 0x01}, // ? - IMX477
    // {0x9371, 0x6A}, // ? - IMX477
    // {0x9373, 0x6A}, // ? - IMX477
    // {0x9375, 0x64}, // ? - IMX477
    // {0x991A, 0x00}, // ? - IMX477
    // {0x996B, 0x8C}, // ? - IMX477
    // {0x996C, 0x64}, // ? - IMX477
    // {0x996D, 0x50}, // ? - IMX477
    // {0x9A4C, 0x0D}, // ? - IMX477
    // {0x9A4D, 0x0D}, // ? - IMX477
    // {0xA001, 0x0A}, // ? - IMX477
    // {0xA003, 0x0A}, // ? - IMX477
    // {0xA005, 0x0A}, // ? - IMX477
    // {0xA006, 0x01}, // ? - IMX477
    // {0xA007, 0xC0}, // ? - IMX477
    // {0xA009, 0xC0}, // ? - IMX477
    // {0x3D8A, 0x01}, // ? - IMX477
    // {0x4421, 0x04}, // ? - IMX477
    // {0x7B3B, 0x01}, // ? - IMX477
    // {0x7B4C, 0x00}, // ? - IMX477
    // {0x9905, 0x00}, // ? - IMX477
    // {0x9907, 0x00}, // ? - IMX477
    // {0x9909, 0x00}, // ? - IMX477
    // {0x990B, 0x00}, // ? - IMX477
    // {0x9944, 0x3C}, // ? - IMX477
    // {0x9947, 0x3C}, // ? - IMX477
    // {0x994A, 0x8C}, // ? - IMX477
    // {0x994B, 0x50}, // ? - IMX477
    // {0x994C, 0x1B}, // ? - IMX477
    // {0x994D, 0x8C}, // ? - IMX477
    // {0x994E, 0x50}, // ? - IMX477
    // {0x994F, 0x1B}, // ? - IMX477
    // {0x9950, 0x8C}, // ? - IMX477
    // {0x9951, 0x1B}, // ? - IMX477
    // {0x9952, 0x0A}, // ? - IMX477
    // {0x9953, 0x8C}, // ? - IMX477
    // {0x9954, 0x1B}, // ? - IMX477
    // {0x9955, 0x0A}, // ? - IMX477
    // {0x9A13, 0x04}, // ? - IMX477
    // {0x9A14, 0x04}, // ? - IMX477
    // {0x9A19, 0x00}, // ? - IMX477
    // {0x9A1C, 0x04}, // ? - IMX477
    // {0x9A1D, 0x04}, // ? - IMX477
    // {0x9A26, 0x05}, // ? - IMX477
    // {0x9A27, 0x05}, // ? - IMX477
    // {0x9A2C, 0x01}, // ? - IMX477
    // {0x9A2D, 0x03}, // ? - IMX477
    // {0x9A2F, 0x05}, // ? - IMX477
    // {0x9A30, 0x05}, // ? - IMX477
    // {0x9A41, 0x00}, // ? - IMX477
    // {0x9A46, 0x00}, // ? - IMX477
    // {0x9A47, 0x00}, // ? - IMX477
    // {0x9C17, 0x35}, // ? - IMX477
    // {0x9C1D, 0x31}, // ? - IMX477
    // {0x9C29, 0x50}, // ? - IMX477
    // {0x9C3B, 0x2F}, // ? - IMX477
    // {0x9C41, 0x6B}, // ? - IMX477
    // {0x9C47, 0x2D}, // ? - IMX477
    // {0x9C4D, 0x40}, // ? - IMX477
    // {0x9C6B, 0x00}, // ? - IMX477
    // {0x9C71, 0xC8}, // ? - IMX477
    // {0x9C73, 0x32}, // ? - IMX477
    // {0x9C75, 0x04}, // ? - IMX477
    // {0x9C7D, 0x2D}, // ? - IMX477
    // {0x9C83, 0x40}, // ? - IMX477
    // {0x9C94, 0x3F}, // ? - IMX477
    // {0x9C95, 0x3F}, // ? - IMX477
    // {0x9C96, 0x3F}, // ? - IMX477
    // {0x9C97, 0x00}, // ? - IMX477
    // {0x9C98, 0x00}, // ? - IMX477
    // {0x9C99, 0x00}, // ? - IMX477
    // {0x9C9A, 0x3F}, // ? - IMX477
    // {0x9C9B, 0x3F}, // ? - IMX477
    // {0x9C9C, 0x3F}, // ? - IMX477
    // {0x9CA0, 0x0F}, // ? - IMX477
    // {0x9CA1, 0x0F}, // ? - IMX477
    // {0x9CA2, 0x0F}, // ? - IMX477
    // {0x9CA3, 0x00}, // ? - IMX477
    // {0x9CA4, 0x00}, // ? - IMX477
    // {0x9CA5, 0x00}, // ? - IMX477
    // {0x9CA6, 0x1E}, // ? - IMX477
    // {0x9CA7, 0x1E}, // ? - IMX477
    // {0x9CA8, 0x1E}, // ? - IMX477
    // {0x9CA9, 0x00}, // ? - IMX477
    // {0x9CAA, 0x00}, // ? - IMX477
    // {0x9CAB, 0x00}, // ? - IMX477
    // {0x9CAC, 0x09}, // ? - IMX477
    // {0x9CAD, 0x09}, // ? - IMX477
    // {0x9CAE, 0x09}, // ? - IMX477
    // {0x9CBD, 0x50}, // ? - IMX477
    // {0x9CBF, 0x50}, // ? - IMX477
    // {0x9CC1, 0x50}, // ? - IMX477
    // {0x9CC3, 0x40}, // ? - IMX477
    // {0x9CC5, 0x40}, // ? - IMX477
    // {0x9CC7, 0x40}, // ? - IMX477
    // {0x9CC9, 0x0A}, // ? - IMX477
    // {0x9CCB, 0x0A}, // ? - IMX477
    // {0x9CCD, 0x0A}, // ? - IMX477
    // {0x9D17, 0x35}, // ? - IMX477
    // {0x9D1D, 0x31}, // ? - IMX477
    // {0x9D29, 0x50}, // ? - IMX477
    // {0x9D3B, 0x2F}, // ? - IMX477
    // {0x9D41, 0x6B}, // ? - IMX477
    // {0x9D47, 0x42}, // ? - IMX477
    // {0x9D4D, 0x5A}, // ? - IMX477
    // {0x9D6B, 0x00}, // ? - IMX477
    // {0x9D71, 0xC8}, // ? - IMX477
    // {0x9D73, 0x32}, // ? - IMX477
    // {0x9D75, 0x04}, // ? - IMX477
    // {0x9D7D, 0x42}, // ? - IMX477
    // {0x9D83, 0x5A}, // ? - IMX477
    // {0x9D94, 0x3F}, // ? - IMX477
    // {0x9D95, 0x3F}, // ? - IMX477
    // {0x9D96, 0x3F}, // ? - IMX477
    // {0x9D97, 0x00}, // ? - IMX477
    // {0x9D98, 0x00}, // ? - IMX477
    // {0x9D99, 0x00}, // ? - IMX477
    // {0x9D9A, 0x3F}, // ? - IMX477
    // {0x9D9B, 0x3F}, // ? - IMX477
    // {0x9D9C, 0x3F}, // ? - IMX477
    // {0x9D9D, 0x1F}, // ? - IMX477
    // {0x9D9E, 0x1F}, // ? - IMX477
    // {0x9D9F, 0x1F}, // ? - IMX477
    // {0x9DA0, 0x0F}, // ? - IMX477
    // {0x9DA1, 0x0F}, // ? - IMX477
    // {0x9DA2, 0x0F}, // ? - IMX477
    // {0x9DA3, 0x00}, // ? - IMX477
    // {0x9DA4, 0x00}, // ? - IMX477
    // {0x9DA5, 0x00}, // ? - IMX477
    // {0x9DA6, 0x1E}, // ? - IMX477
    // {0x9DA7, 0x1E}, // ? - IMX477
    // {0x9DA8, 0x1E}, // ? - IMX477
    // {0x9DA9, 0x00}, // ? - IMX477
    // {0x9DAA, 0x00}, // ? - IMX477
    // {0x9DAB, 0x00}, // ? - IMX477
    // {0x9DAC, 0x09}, // ? - IMX477
    // {0x9DAD, 0x09}, // ? - IMX477
    // {0x9DAE, 0x09}, // ? - IMX477
    // {0x9DC9, 0x0A}, // ? - IMX477
    // {0x9DCB, 0x0A}, // ? - IMX477
    // {0x9DCD, 0x0A}, // ? - IMX477
    // {0x9E17, 0x35}, // ? - IMX477
    // {0x9E1D, 0x31}, // ? - IMX477
    // {0x9E29, 0x50}, // ? - IMX477
    // {0x9E3B, 0x2F}, // ? - IMX477
    // {0x9E41, 0x6B}, // ? - IMX477
    // {0x9E47, 0x2D}, // ? - IMX477
    // {0x9E4D, 0x40}, // ? - IMX477
    // {0x9E6B, 0x00}, // ? - IMX477
    // {0x9E71, 0xC8}, // ? - IMX477
    // {0x9E73, 0x32}, // ? - IMX477
    // {0x9E75, 0x04}, // ? - IMX477
    // {0x9E94, 0x0F}, // ? - IMX477
    // {0x9E95, 0x0F}, // ? - IMX477
    // {0x9E96, 0x0F}, // ? - IMX477
    // {0x9E97, 0x00}, // ? - IMX477
    // {0x9E98, 0x00}, // ? - IMX477
    // {0x9E99, 0x00}, // ? - IMX477
    // {0x9EA0, 0x0F}, // ? - IMX477
    // {0x9EA1, 0x0F}, // ? - IMX477
    // {0x9EA2, 0x0F}, // ? - IMX477
    // {0x9EA3, 0x00}, // ? - IMX477
    // {0x9EA4, 0x00}, // ? - IMX477
    // {0x9EA5, 0x00}, // ? - IMX477
    // {0x9EA6, 0x3F}, // ? - IMX477
    // {0x9EA7, 0x3F}, // ? - IMX477
    // {0x9EA8, 0x3F}, // ? - IMX477
    // {0x9EA9, 0x00}, // ? - IMX477
    // {0x9EAA, 0x00}, // ? - IMX477
    // {0x9EAB, 0x00}, // ? - IMX477
    // {0x9EAC, 0x09}, // ? - IMX477
    // {0x9EAD, 0x09}, // ? - IMX477
    // {0x9EAE, 0x09}, // ? - IMX477
    // {0x9EC9, 0x0A}, // ? - IMX477
    // {0x9ECB, 0x0A}, // ? - IMX477
    // {0x9ECD, 0x0A}, // ? - IMX477
    // {0x9F17, 0x35}, // ? - IMX477
    // {0x9F1D, 0x31}, // ? - IMX477
    // {0x9F29, 0x50}, // ? - IMX477
    // {0x9F3B, 0x2F}, // ? - IMX477
    // {0x9F41, 0x6B}, // ? - IMX477
    // {0x9F47, 0x42}, // ? - IMX477
    // {0x9F4D, 0x5A}, // ? - IMX477
    // {0x9F6B, 0x00}, // ? - IMX477
    // {0x9F71, 0xC8}, // ? - IMX477
    // {0x9F73, 0x32}, // ? - IMX477
    // {0x9F75, 0x04}, // ? - IMX477
    // {0x9F94, 0x0F}, // ? - IMX477
    // {0x9F95, 0x0F}, // ? - IMX477
    // {0x9F96, 0x0F}, // ? - IMX477
    // {0x9F97, 0x00}, // ? - IMX477
    // {0x9F98, 0x00}, // ? - IMX477
    // {0x9F99, 0x00}, // ? - IMX477
    // {0x9F9A, 0x2F}, // ? - IMX477
    // {0x9F9B, 0x2F}, // ? - IMX477
    // {0x9F9C, 0x2F}, // ? - IMX477
    // {0x9F9D, 0x00}, // ? - IMX477
    // {0x9F9E, 0x00}, // ? - IMX477
    // {0x9F9F, 0x00}, // ? - IMX477
    // {0x9FA0, 0x0F}, // ? - IMX477
    // {0x9FA1, 0x0F}, // ? - IMX477
    // {0x9FA2, 0x0F}, // ? - IMX477
    // {0x9FA3, 0x00}, // ? - IMX477
    // {0x9FA4, 0x00}, // ? - IMX477
    // {0x9FA5, 0x00}, // ? - IMX477
    // {0x9FA6, 0x1E}, // ? - IMX477
    // {0x9FA7, 0x1E}, // ? - IMX477
    // {0x9FA8, 0x1E}, // ? - IMX477
    // {0x9FA9, 0x00}, // ? - IMX477
    // {0x9FAA, 0x00}, // ? - IMX477
    // {0x9FAB, 0x00}, // ? - IMX477
    // {0x9FAC, 0x09}, // ? - IMX477
    // {0x9FAD, 0x09}, // ? - IMX477
    // {0x9FAE, 0x09}, // ? - IMX477
    // {0x9FC9, 0x0A}, // ? - IMX477
    // {0x9FCB, 0x0A}, // ? - IMX477
    // {0x9FCD, 0x0A}, // ? - IMX477
    // {0xA14B, 0xFF}, // ? - IMX477
    // {0xA151, 0x0C}, // ? - IMX477
    // {0xA153, 0x50}, // ? - IMX477
    // {0xA155, 0x02}, // ? - IMX477
    // {0xA157, 0x00}, // ? - IMX477
    // {0xA1AD, 0xFF}, // ? - IMX477
    // {0xA1B3, 0x0C}, // ? - IMX477
    // {0xA1B5, 0x50}, // ? - IMX477
    // {0xA1B9, 0x00}, // ? - IMX477
    // {0xA24B, 0xFF}, // ? - IMX477
    // {0xA257, 0x00}, // ? - IMX477
    // {0xA2AD, 0xFF}, // ? - IMX477
    // {0xA2B9, 0x00}, // ? - IMX477
    // {0xB21F, 0x04}, // ? - IMX477
    // {0xB35C, 0x00}, // ? - IMX477
    // {0xB35E, 0x08}, // ? - IMX477
 
    {0x38A8, 0x1F},
    {0x38A9, 0xFF},
    {0x38AA, 0x1F},
    {0x38AB, 0xFF},
    {0x55D4, 0x00},
    {0x55D5, 0x00},
    {0x55D6, 0x07},
    {0x55D7, 0xFF},
    {0x55E8, 0x07},
    {0x55E9, 0xFF},
    {0x55EA, 0x00},
    {0x55EB, 0x00},
    {0x575C, 0x07},
    {0x575D, 0xFF},
    {0x575E, 0x00},
    {0x575F, 0x00},
    {0x5764, 0x00},
    {0x5765, 0x00},
    {0x5766, 0x07},
    {0x5767, 0xFF},
    {0x5974, 0x04},
    {0x5975, 0x01},
    {0x5F10, 0x09},
    {0x5F11, 0x92},
    {0x5F12, 0x32},
    {0x5F13, 0x72},
    {0x5F14, 0x16},
    {0x5F15, 0xBA},
    {0x5F17, 0x13},
    {0x5F18, 0x24},
    {0x5F19, 0x60},
    {0x5F1A, 0xE3},
    {0x5F1B, 0xAD},
    {0x5F1C, 0x74},
    {0x5F2D, 0x25},
    {0x5F5C, 0xD0},
    {0x6A22, 0x00},
    {0x6A23, 0x1D},
    {0x7BA8, 0x00},
    {0x7BA9, 0x00},
    {0x886B, 0x00},
    {0x9002, 0x0A},
    {0x9004, 0x1A},
    {0x9214, 0x93},
    {0x9215, 0x69},
    {0x9216, 0x93},
    {0x9217, 0x6B},
    {0x9218, 0x93},
    {0x9219, 0x6D},
    {0x921A, 0x57},
    {0x921B, 0x58},
    {0x921C, 0x57},
    {0x921D, 0x59},
    {0x921E, 0x57},
    {0x921F, 0x5A},
    {0x9220, 0x57},
    {0x9221, 0x5B},
    {0x9222, 0x93},
    {0x9223, 0x02},
    {0x9224, 0x93},
    {0x9225, 0x03},
    {0x9226, 0x93},
    {0x9227, 0x04},
    {0x9228, 0x93},
    {0x9229, 0x05},
    {0x922A, 0x98},
    {0x922B, 0x21},
    {0x922C, 0xB2},
    {0x922D, 0xDB},
    {0x922E, 0xB2},
    {0x922F, 0xDC},
    {0x9230, 0xB2},
    {0x9231, 0xDD},
    {0x9232, 0xB2},
    {0x9233, 0xE1},
    {0x9234, 0xB2},
    {0x9235, 0xE2},
    {0x9236, 0xB2},
    {0x9237, 0xE3},
    {0x9238, 0xB7},
    {0x9239, 0xB9},
    {0x923A, 0xB7},
    {0x923B, 0xBB},
    {0x923C, 0xB7},
    {0x923D, 0xBC},
    {0x923E, 0xB7},
    {0x923F, 0xC5},
    {0x9240, 0xB7},
    {0x9241, 0xC7},
    {0x9242, 0xB7},
    {0x9243, 0xC9},
    {0x9244, 0x98},
    {0x9245, 0x56},
    {0x9246, 0x98},
    {0x9247, 0x55},
    {0x9380, 0x00},
    {0x9381, 0x62},
    {0x9382, 0x00},
    {0x9383, 0x56},
    {0x9384, 0x00},
    {0x9385, 0x52},
    {0x9388, 0x00},
    {0x9389, 0x55},
    {0x938A, 0x00},
    {0x938B, 0x55},
    {0x938C, 0x00},
    {0x938D, 0x41},
    {0x5078, 0x01},
 
    // Non base, but repeated configurations:
    {IMX477_CSI_LANE_MODE, IMX477_CSI_LANE_MODE_4LANES}, // IMX577 compatible
    {IMX477_DOL_EN_REGISTER, 0x00},
    {0xE013, 0x00},                      // Datasheets states that this should be set (for IMX477 and IMX577)
    {IMX477_DOL_NUM_REGISTER, 0x00},     // IMX577 compatible
    {IMX477_DOL_CSI_DT_FMT_H_2ND, 0x0A}, // IMX577 compatible
    {IMX477_DOL_CSI_DT_FMT_L_2ND, 0x0A}, // IMX577 compatible
    {IMX477_DOL_CSI_DT_FMT_H_3RD, 0x0A}, // IMX577 compatible
    {IMX477_DOL_CSI_DT_FMT_L_3RD, 0x0A}, // IMX577 compatible
    // {0x3140, 0x02}, // ? - IMX477
    // {0x3C00, 0x00}, // ? - IMX477
    // {0x3C01, 0x03}, // ? - IMX477
    // {0x3C02, 0xA2}, // ? - IMX477
    // {0x3F0D, 0x01}, // IMX577 compatible - IMX477
    // {0x5748, 0x07}, // ? - IMX477
    // {0x5749, 0xFF}, // ? - IMX477
    // {0x574A, 0x00}, // ? - IMX477
    // {0x574B, 0x00}, // ? - IMX477
    // {0x7B75, 0x0A}, // ? - IMX477
    // {0x7B76, 0x0C}, // ? - IMX477
    // {0x7B77, 0x07}, // ? - IMX477
    // {0x7B78, 0x06}, // ? - IMX477
    // {0x7B79, 0x3C}, // ? - IMX477
    // {0x7B53, 0x01}, // ? - IMX477
    // {0x9369, 0x5A}, // ? - IMX477
    // {0x936B, 0x55}, // ? - IMX477
    // {0x936D, 0x28}, // ? - IMX477
    // {0x9304, 0x00}, // ? - IMX477
    // {0x9305, 0x00}, // ? - IMX477
    // {0x9E9A, 0x2F}, // ? - IMX477
    // {0x9E9B, 0x2F}, // ? - IMX477
    // {0x9E9C, 0x2F}, // ? - IMX477
    // {0x9E9D, 0x00}, // ? - IMX477
    // {0x9E9E, 0x00}, // ? - IMX477
    // {0x9E9F, 0x00}, // ? - IMX477
    // {0xA2A9, 0x60}, // ? - IMX477
    // {0xA2B7, 0x00}, // ? - IMX477
    {IMX477_IVT_PXCK_DIV, 0x05},                 // IMX577 allows only 5 in here, which is fine for us.
    {IMX477_IVT_SYCK_DIV, 0x02},                 // IMX577 compatible
    {IMX477_IVT_PREPLLCK_DIV, 0x04},             // IMX577 compatible
    {IMX477_IVT_PLL_MPY_10_8, 0x01},             // IMX577 this is a 12-bit value rather than 11-bit - OK
    {IMX477_IVT_PLL_MPY_7_0, 0x5E},              // IMX577 this is a 12-bit value rather than 11-bit - OK
    {IMX477_IOP_PXCK_DIV, 0x0C},                 // IMX577 compatible
    {IMX477_IOP_SYCK_DIV, 0x04},                 // IMX577 compatible
    {IMX477_IOP_PREPLLCK_DIV, 0x02},             // IMX577 compatible
    {IMX477_IOP_PLL_MPY_10_8, 0x00},             // IMX577 this is a 12-bit value rather than 11-bit - OK
    {IMX477_IOP_PLL_MPY_7_0, 0xBD},              // IMX577 this is a 12-bit value rather than 11-bit - OK
    {IMX477_PLL_MULT_DRIV, 0x01},                // IMX577 compatible
    {IMX477_REQ_LINK_BIT_RATE_MBPS_31_24, 0x07}, // IMX577 compatible
    {IMX477_REQ_LINK_BIT_RATE_MBPS_23_16, 0x08}, // IMX577 compatible
    {IMX477_REQ_LINK_BIT_RATE_MBPS_15_8, 0x00},  // IMX577 compatible
    {IMX477_REQ_LINK_BIT_RATE_MBPS_7_0, 0x00},   // IMX577 compatible
    {IMX477_TCLK_POST_EX_9_8, 0x00},             // IMX577 compatible
    {IMX477_TCLK_POST_EX_7_0, 0x7F},             // IMX577 compatible
    {IMX477_THS_PREPARE_EX_9_8, 0x00},           // IMX577 compatible
    {IMX477_THS_PREPARE_EX_7_0, 0x4F},           // IMX577 compatible
    {IMX477_THS_ZERO_MIN_EX_9_8, 0x00},          // IMX577 compatible
    {IMX477_THS_ZERO_MIN_EX_7_0, 0x77},          // IMX577 compatible
    {IMX477_THS_TRAIL_EX_9_8, 0x00},             // IMX577 compatible
    {IMX477_THS_TRAIL_EX_7_0, 0x5F},             // IMX577 compatible
    {IMX477_TCLK_TRAIL_MIN_EX_9_8, 0x00},        // IMX577 compatible
    {IMX477_TCLK_TRAIL_MIN_EX_7_0, 0x57},        // IMX577 compatible
    {IMX477_TCLK_PREPARE_EX_9_8, 0x00},          // IMX577 compatible
    {IMX477_TCLK_PREPARE_EX_7_0, 0x4F},          // IMX577 compatible
    {IMX477_TCLK_ZERO_EX_9_8, 0x01},             // IMX577 compatible
    {IMX477_TCLK_ZERO_EX_7_0, 0x27},             // IMX577 compatible
    {IMX477_TLPX_EX_9_8, 0x00},                  // IMX577 compatible
    {IMX477_TLPX_EX_7_0, 0x3F},                  // IMX577 compatible
    // {0xE04C, 0x00}, // ? - IMX477
    // {0xE04D, 0x7F}, // ? - IMX477
    // {0xE04E, 0x00}, // ? - IMX477
    // {0xE04F, 0x1F}, // ? - IMX477
    // {0x3E20, 0x01}, // ? - IMX477
    {IMX477_PDAF_CTRL1_0, 0x00},          // Doesn't apply for IMX577
    {IMX477_POWER_SAVE_ENABLE, 0x00},     // IMX577 compatible
    {IMX477_LINE_LENGTH_INCK_15_8, 0x02}, // IMX577 compatible
    {IMX477_LINE_LENGTH_INCK_7_0, 0xAE},  // IMX577 compatible
    {IMX477_IMG_ORIENTATION_V_H, 0x00},   // IMX577 compatible
    {IMX477_MAP_COUP_CORR_EN, 0x01},      // IMX577 compatible
    {IMX477_SING_DEF_CORR_EN, 0x01},      // IMX577 compatible
    {IMX477_FLASH_TRIG_RS, 0x00},         // IMX577 compatible
 
    /// Debug signals
    {IMX477_TESTMNT0, 0xFF},
    {IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0] // IMX577 compatible
    {IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0] // IMX577 compatible
    // {IMX477_MNTTEST2_SEL_8, 0x00},   // MNTTEST2_SEL[8], 22d: V sync is selected. // IMX577 compatible
    // {IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0] // IMX577 compatible
    // {IMX477_MNTTEST3_SEL_8, 0x00},   // MNTTEST3_SEL[8], 21d: H sync is selected. // IMX577 compatible
    // {IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0] // IMX577 compatible
    {IMX477_MNTTEST1_SEL_8, 0x00},
    {IMX477_MNTTEST1_SEL_7_0, 0x16},
    {IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting. // IMX577 compatible
    {IMX477_GPIOSEL, 0x00},     // GPIOSEL, 00h: GPIO0 pin is selected. // IMX577 compatible
    {IMX477_VSYNC_POL, 0x00},   // VSYNC_POL // IMX577 compatible
    {IMX477_VSYNC_WID, 0x03},   // VSYNC_WID // IMX577 compatible
    {IMX477_HSYNC_POL, 0x00},   // HSYNC_POL // IMX577 compatible
    {IMX477_HSYNC_WID, 0x03},   // HSYNC_WID // IMX577 compatible
    {IMX477_CKTESTSEL, 0x00},   // IMX577 compatible
    ///
 
    {IMX477_DPGA_USE_GLOBAL_GAIN, 0x00}, // IMX577 compatible
    {IMX477_MANUAL_DATA_PEDESTAL_EN_REGISTER, IMX477_MANUAL_DATA_PEDESTAL_MANUAL_VALUE},
    {IMX477_MANUAL_DATA_PEDESTAL_VALUE_11_8, 0x00}, // IMX577 compatible
    {IMX477_MANUAL_DATA_PEDESTAL_VALUE_7_0, 0x00},  // IMX577 compatible
 
    {IMX477_SHORT_FRAME_RS, IMX477_SHORT_FRAME_RS_NORMAL}, // IMX577 compatible
 
    {IMX477_CSI_DT_FMT_H, 0x08}, // IMX577 compatible
    {IMX477_CSI_DT_FMT_L, 0x08}, // IMX577 compatible
    {IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},                               // IMX577 compatible
    {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},                                // IMX577 compatible
    {IMX477_X_ADD_STA_12_8, 0x00},                                      // IMX577 compatible
    {IMX477_X_ADD_STA_7_0, 0x00},                                       // IMX577 compatible
    {IMX477_Y_ADD_STA_12_8, 0x00},                                      // IMX577 compatible
    {IMX477_Y_ADD_STA_7_0, 0x00},                                       // IMX577 compatible
    {IMX477_X_ADD_END_12_8, 0x0F},                                      // IMX577 compatible
    {IMX477_X_ADD_END_7_0, 0xD7},                                       // IMX577 compatible
    {IMX477_Y_ADD_END_12_8, 0x0B},                                      // IMX577 compatible
    {IMX477_Y_ADD_END_7_0, 0xDF},                                       // IMX577 compatible
    {IMX477_X_EVN_INC, 0x01},                                           // IMX577 compatible
    {IMX477_X_ODD_INC, 0x01},                                           // IMX577 compatible
    {IMX477_Y_EVN_INC, 0x01},                                           // IMX577 compatible
    {IMX477_Y_ODD_INC, 0x01},                                           // IMX577 compatible
    {IMX477_BINNING_WEIGHTING, 0x02},                                   // IMX577 compatible
    {IMX477_BINNING_SUB_WEIGHTING, 0x03},                               // Required in IMX577!!!!
    {IMX477_SCALE_M_8, 0x00},                                           // IMX577 compatible
    {IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},                              // IMX577 compatible
    {IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},                               // IMX577 compatible
    {IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},                              // IMX577 compatible
    {IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},                               // IMX577 compatible
    {IMX477_IOP_PXCK_DIV, 0x08},                                        // IMX577 compatible
    {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},                               // IMX577 compatible
    {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},                                // IMX577 compatible
    {IMX477_CIT_LSHIFT, 0x00},                                          // IMX577 compatible
    {IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES}, // IMX577 compatible
    {IMX477_TEMP_SEN_OUT, IMX477_TEMP_SEN_OUT_ENABLED},
 
    /// Setting up the strobe signal
    {0x4288, 0x0},
    {0x0C1A, 0x01},
    {0x0C1B, 0x01},
    {0x0C18, 0x87},
    {0x0C19, 0x10}};
 
    


uint32_t RAW12_4056x3040_LINE_LENGTH_PCK = 0xBB80;

I2CReg SENSOR_RAW12_4056x3040_ConfigurationSettings[] = {

    // {IMX477_CSI_DT_FMT_H, 0x0C},
    // {IMX477_CSI_DT_FMT_L, 0x0C},
    // //		{IMX477_CSI_LANE_MODE,0x01},
    // {IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0xBB},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0x80},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_X_ADD_STA_12_8, 0x00},
    // {IMX477_X_ADD_STA_7_0, 0x00},
    // {IMX477_Y_ADD_STA_12_8, 0x00},
    // {IMX477_Y_ADD_STA_7_0, 0x00},
    // {IMX477_X_ADD_END_12_8, 0x0F},
    // {IMX477_X_ADD_END_7_0, 0xD7},
    // {IMX477_Y_ADD_END_12_8, 0x0B},
    // {IMX477_Y_ADD_END_7_0, 0xDF},
    // //		{IMX477_DOL_EN_REGISTER,0x00},
    // //		{IMX477_DOL_NUM_REGISTER,0x00},
    // //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    // //		{IMX477_SME_HDR_MODE,0x00},
    // //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    // {IMX477_X_EVN_INC, 0x01},
    // {IMX477_X_ODD_INC, 0x01},
    // {IMX477_Y_EVN_INC, 0x01},
    // {IMX477_Y_ODD_INC, 0x01},
    // {IMX477_BINNING_MODE, 0x00},
    // {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x11},
    // {IMX477_BINNING_WEIGHTING, 0x02},
    // //		{0x3140,0x02},
    // //		{0x3C00,0x00},
    // //		{0x3C01,0x03},
    // //		{0x3C02,0xA2},
    // //		{0x3F0D,0x01},
    // //		{0x5748,0x07},
    // //		{0x5749,0xFF},
    // //		{0x574A,0x00},
    // //		{0x574B,0x00},
    // //		{0x7B75,0x0A},
    // //		{0x7B76,0x0C},
    // //		{0x7B77,0x07},
    // //		{0x7B78,0x06},
    // //		{0x7B79,0x3C},
    // //		{0x7B53,0x01},
    // //		{0x9369,0x5A},
    // //		{0x936B,0x55},
    // //		{0x936D,0x28},
    // //		{0x9304,0x00},
    // //		{0x9305,0x00},
    // //		{0x9E9A,0x2F},
    // //		{0x9E9B,0x2F},
    // //		{0x9E9C,0x2F},
    // //		{0x9E9D,0x00},
    // //		{0x9E9E,0x00},
    // //		{0x9E9F,0x00},
    // //		{0xA2A9,0x60},
    // //		{0xA2B7,0x00},
    // {IMX477_SCALE_MODE, 0x00},
    // {IMX477_SCALE_M_8, 0x00},
    // {IMX477_SCALE_M_7_0, 0x10},
    // {IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x0F},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xD8},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x0B},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xE0},
    // {IMX477_X_OUT_SIZE_12_8, 0x0F},
    // {IMX477_X_OUT_SIZE_7_0, 0xD8},
    // {IMX477_Y_OUT_SIZE_12_8, 0x0B},
    // {IMX477_Y_OUT_SIZE_7_0, 0xE0},
    // //		{IMX477_IVT_PXCK_DIV,0x05},
    // //		{IMX477_IVT_SYCK_DIV,0x02},
    // //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    // //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    // //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    // {IMX477_IOP_PXCK_DIV, 0x0C},
    // //		{IMX477_IOP_SYCK_DIV,0x02},
    // //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    // //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    // //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    // //		{IMX477_PLL_MULT_DRIV,0x01},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    // //		{IMX477_TCLK_POST_EX_9_8,0x00},
    // //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    // //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    // //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    // //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    // //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    // //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    // //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    // //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    // //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    // //		{IMX477_TLPX_EX_9_8,0x00},
    // //		{IMX477_TLPX_EX_7_0,0x3F},
    // //		{0xE04C,0x00},
    // //		{0xE04D,0x7F},
    // //		{0xE04E,0x00},
    // //		{0xE04F,0x1F},
    // //		{0x3E20,0x01},
    // //		{IMX477_PDAF_CTRL1_0,0x00},
    // //		{IMX477_POWER_SAVE_ENABLE,0x00},
    // //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    // //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    // //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    // //		{IMX477_MAP_COUP_CORR_EN,0x01},
    // //		{IMX477_SING_DEF_CORR_EN,0x01},

    // // {IMX477_GRP_PARAM_HOLD, 0x01},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0xBB},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0x80},
    // {IMX477_CIT_LSHIFT, 0x00},
    // // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // // {IMX477_GRP_PARAM_HOLD, 0x00},

    // //		{IMX477_FLASH_TRIG_RS,0x00},

    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    // //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},
    // //
    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    // //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    // //		{IMX477_LINE_LENGTH_PCK_15_8,0xBB},
    // //		{IMX477_LINE_LENGTH_PCK_7_0,0x80},
    // //		{IMX477_CIT_LSHIFT,0x00},
    // //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    // //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},

    // //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    // //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    // //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    // {IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    // {IMX477_TESTMNT1, 0xfe},         // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    // {IMX477_TESTMNT2, 0xfd},         // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    // {IMX477_MNTTEST2_SEL_8, 0x00},   // MNTTEST2_SEL[8], 22d: V sync is selected.
    // {IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    // {IMX477_MNTTEST3_SEL_8, 0x00},   // MNTTEST3_SEL[8], 21d: H sync is selected.
    // {IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    // {IMX477_XVS_IO_CTRL, 0x01},      // XVS pin control, 1h: XVS pin : Output setting
    // {IMX477_VSYNC_POL, 0x00},        // VSYNC_POL
    // {IMX477_VSYNC_WID, 0x07},        // VSYNC_WID
    // {IMX477_HSYNC_POL, 0x00},        // HSYNC_POL
    // {IMX477_HSYNC_WID, 0x06},        // HSYNC_WID
    // {IMX477_CKTESTSEL, 0x00},

    // //		{IMX477_MANUAL_DATA_PEDESTAL_EN_REGISTER,IMX477_MANUAL_DATA_PEDESTAL_MANUAL_VALUE},
    // //		{IMX477_MANUAL_DATA_PEDESTAL_VALUE_11_8,0x00},
    // //		{IMX477_MANUAL_DATA_PEDESTAL_VALUE_7_0,0x00},
    // //
    // //        {IMX477_TP_MODE_7_0, 0x01},
    // //        {IMX477_TD_R_11_8,0x00},
    // //        {IMX477_TD_R_7_0,0x01},
    // //        {IMX477_TD_GR_11_8,0x0C},
    // //        {IMX477_TD_GR_7_0,0x9E},
    // //        {IMX477_TD_B_11_8,0x0E},
    // //        {IMX477_TD_B_7_0,0x9C},
    // //        {IMX477_TD_GB_11_8,0x0F},
    // //        {IMX477_TD_GB_7_0,0xFF},

};

uint32_t RAW8_4056x3040_LINE_LENGTH_PCK = 0x5DC0;
I2CReg SENSOR_RAW8_4056x3040_ConfigurationSettings[] = {
    // {IMX477_GRP_PARAM_HOLD, 0x01},
    ////{IMX477_CSI_DT_FMT_H, 0x08},
    ////{IMX477_CSI_DT_FMT_L, 0x08},
    //		{IMX477_CSI_LANE_MODE,0x01},
    ////{IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    {IMX477_LINE_LENGTH_PCK_15_8, 0x5D}, // IMX577 compatible
    {IMX477_LINE_LENGTH_PCK_7_0, 0xC0}, // IMX577 compatible
    ////{IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    ////{IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    ////{IMX477_X_ADD_STA_12_8, 0x00},
    ////{IMX477_X_ADD_STA_7_0, 0x00},
    ////{IMX477_Y_ADD_STA_12_8, 0x00},
    ////{IMX477_Y_ADD_STA_7_0, 0x00},
    ////{IMX477_X_ADD_END_12_8, 0x0F},
    ////{IMX477_X_ADD_END_7_0, 0xD7},
    ////{IMX477_Y_ADD_END_12_8, 0x0B},
    ////{IMX477_Y_ADD_END_7_0, 0xDF},
    //		{IMX477_DOL_EN_REGISTER,0x00},
    //		{IMX477_DOL_NUM_REGISTER,0x00},
    //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    //		{IMX477_SME_HDR_MODE,0x00},
    //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    ////{IMX477_X_EVN_INC, 0x01},
    ////{IMX477_X_ODD_INC, 0x01},
    ////{IMX477_Y_EVN_INC, 0x01},
    ////{IMX477_Y_ODD_INC, 0x01},
    {IMX477_BINNING_MODE, 0x00}, // IMX577 compatible
    {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x11}, // IMX577 compatible - but IMX577 has more binning on the horizontal direction.
    ////{IMX477_BINNING_WEIGHTING, 0x02},
    //		{0x3140,0x02},
    //		{0x3C00,0x00},
    //		{0x3C01,0x03},
    //		{0x3C02,0xA2},
    //		{0x3F0D,0x01},
    //		{0x5748,0x07},
    //		{0x5749,0xFF},
    //		{0x574A,0x00},
    //		{0x574B,0x00},
    //		{0x7B75,0x0A},
    //		{0x7B76,0x0C},
    //		{0x7B77,0x07},
    //		{0x7B78,0x06},
    //		{0x7B79,0x3C},
    //		{0x7B53,0x01},
    //		{0x9369,0x5A},
    //		{0x936B,0x55},
    //		{0x936D,0x28},
    //		{0x9304,0x00},
    //		{0x9305,0x00},
    //		{0x9E9A,0x2F},
    //		{0x9E9B,0x2F},
    //		{0x9E9C,0x2F},
    //		{0x9E9D,0x00},
    //		{0x9E9E,0x00},
    //		{0x9E9F,0x00},
    //		{0xA2A9,0x60},
    //		{0xA2B7,0x00},
    {IMX477_SCALE_MODE, 0x00}, // IMX577 compatible
    ////{IMX477_SCALE_M_8, 0x00},
    {IMX477_SCALE_M_7_0, 0x10}, // IMX577 compatible
    ////{IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    ////{IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    ////{IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    ////{IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x0F}, // IMX577 compatible
    {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xD8}, // IMX577 compatible
    {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x0B}, // IMX577 compatible
    {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xE0}, // IMX577 compatible
    {IMX477_X_OUT_SIZE_12_8, 0x0F}, // IMX577 compatible
    {IMX477_X_OUT_SIZE_7_0, 0xD8}, // IMX577 compatible
    {IMX477_Y_OUT_SIZE_12_8, 0x0B}, // IMX577 compatible
    {IMX477_Y_OUT_SIZE_7_0, 0xE0}, // IMX577 compatible
    //		{IMX477_IVT_PXCK_DIV,0x05},
    //		{IMX477_IVT_SYCK_DIV,0x02},
    //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    ////{IMX477_IOP_PXCK_DIV, 0x08},
    //		{IMX477_IOP_SYCK_DIV,0x02},
    //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    //		{IMX477_PLL_MULT_DRIV,0x01},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    //		{IMX477_TCLK_POST_EX_9_8,0x00},
    //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    //		{IMX477_TLPX_EX_9_8,0x00},
    //		{IMX477_TLPX_EX_7_0,0x3F},
    //		{0xE04C,0x00},
    //		{0xE04D,0x7F},
    //		{0xE04E,0x00},
    //		{0xE04F,0x1F},
    //		{0x3E20,0x01},
    //		{IMX477_PDAF_CTRL1_0,0x00},
    //		{IMX477_POWER_SAVE_ENABLE,0x00},
    //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    //		{IMX477_MAP_COUP_CORR_EN,0x01},
    //		{IMX477_SING_DEF_CORR_EN,0x01},

    ////{IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    ////{IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    {IMX477_LINE_LENGTH_PCK_15_8, 0x5D}, // IMX577 compatible
    {IMX477_LINE_LENGTH_PCK_7_0, 0xC0}, // IMX577 compatible
    ////{IMX477_CIT_LSHIFT, 0x00},
    // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // {IMX477_GRP_PARAM_HOLD, 0x00},

    //		{IMX477_FLASH_TRIG_RS,0x00},

    //		{IMX477_GRP_PARAM_HOLD,0x01},
    //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    //		{IMX477_GRP_PARAM_HOLD,0x00},
    //
    //		{IMX477_GRP_PARAM_HOLD,0x01},
    //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    //		{IMX477_LINE_LENGTH_PCK_15_8,0x5D},
    //		{IMX477_LINE_LENGTH_PCK_7_0,0xBF},
    //		{IMX477_CIT_LSHIFT,0x00},
    //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    //		{IMX477_GRP_PARAM_HOLD,0x00},

    //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    ////{IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    //		{IMX477_CKTESTSEL, 0x00},

    //		{IMX477_MANUAL_DATA_PEDESTAL_EN_REGISTER,IMX477_MANUAL_DATA_PEDESTAL_MANUAL_VALUE},
    //		{IMX477_MANUAL_DATA_PEDESTAL_VALUE_11_8,0x00},
    //		{IMX477_MANUAL_DATA_PEDESTAL_VALUE_7_0,0x00},
    //
    //        {IMX477_TP_MODE_7_0, 0x01},
    //        {IMX477_TD_R_11_8,0x00},
    //        {IMX477_TD_R_7_0,0x01},
    //        {IMX477_TD_GR_11_8,0x0C},
    //        {IMX477_TD_GR_7_0,0x9E},
    //        {IMX477_TD_B_11_8,0x0E},
    //        {IMX477_TD_B_7_0,0x9C},
    //        {IMX477_TD_GB_11_8,0x0F},
    //        {IMX477_TD_GB_7_0,0xFF},

    //{0x0100,0x01}
};
/* Configuration settings for 676x504 */
uint32_t RAW8_676x504_LINE_LENGTH_PCK = 0x1770;
I2CReg SENSOR_RAW8_676x504_ConfigurationSettings[] = {
    // {IMX477_CSI_DT_FMT_H, 0x08},
    // {IMX477_CSI_DT_FMT_L, 0x08},

    // {IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x17},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0x70},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_X_ADD_STA_12_8, 0x00},
    // {IMX477_X_ADD_STA_7_0, 0x00},
    // {IMX477_Y_ADD_STA_12_8, 0x00},
    // {IMX477_Y_ADD_STA_7_0, 0x00},
    // {IMX477_X_ADD_END_12_8, 0x0F},
    // {IMX477_X_ADD_END_7_0, 0xD7},
    // {IMX477_Y_ADD_END_12_8, 0x0B},
    // {IMX477_Y_ADD_END_7_0, 0xDF},
    // //		{IMX477_DOL_EN_REGISTER,0x00},
    // //		{IMX477_DOL_NUM_REGISTER,0x00},
    // //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    // //		{IMX477_SME_HDR_MODE,0x00},
    // //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    // {IMX477_X_EVN_INC, 0x01},
    // {IMX477_X_ODD_INC, 0x01},
    // {IMX477_Y_EVN_INC, 0x01},
    // {IMX477_Y_ODD_INC, 0x03},
    // {IMX477_BINNING_MODE, 0x01},
    // {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x22},
    // {IMX477_BINNING_WEIGHTING, 0x02},
    // //		{0x3140,0x02},
    // //		{0x3C00,0x00},
    // //		{0x3C01,0x03},
    // //		{0x3C02,0xA2},
    // //		{0x3F0D,0x01},
    // //		{0x5748,0x07},
    // //		{0x5749,0xFF},
    // //		{0x574A,0x00},
    // //		{0x574B,0x00},
    // //		{0x7B75,0x0A},
    // //		{0x7B76,0x0C},
    // //		{0x7B77,0x07},
    // //		{0x7B78,0x06},
    // //		{0x7B79,0x3C},
    // //		{0x7B53,0x01},
    // //		{0x9369,0x5A},
    // //		{0x936B,0x55},
    // //		{0x936D,0x28},
    // //		{0x9304,0x00},
    // //		{0x9305,0x00},
    // //		{0x9E9A,0x2F},
    // //		{0x9E9B,0x2F},
    // //		{0x9E9C,0x2F},
    // //		{0x9E9D,0x00},
    // //		{0x9E9E,0x00},
    // //		{0x9E9F,0x00},
    // //		{0xA2A9,0x60},
    // //		{0xA2B7,0x00},
    // {IMX477_SCALE_MODE, 0x01},
    // {IMX477_SCALE_M_8, 0x00},
    // {IMX477_SCALE_M_7_0, 0x30},
    // {IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x07},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xEC},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x02},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xF8},
    // {IMX477_X_OUT_SIZE_12_8, 0x02},
    // {IMX477_X_OUT_SIZE_7_0, 0xA4},
    // {IMX477_Y_OUT_SIZE_12_8, 0x02},
    // {IMX477_Y_OUT_SIZE_7_0, 0xF8},
    // //		{IMX477_IVT_PXCK_DIV,0x05},
    // //		{IMX477_IVT_SYCK_DIV,0x02},
    // //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    // //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    // //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    // {IMX477_IOP_PXCK_DIV, 0x08},
    // //		{IMX477_IOP_SYCK_DIV,0x02},
    // //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    // //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    // //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    // //		{IMX477_PLL_MULT_DRIV,0x01},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    // //		{IMX477_TCLK_POST_EX_9_8,0x00},
    // //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    // //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    // //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    // //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    // //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    // //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    // //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    // //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    // //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    // //		{IMX477_TLPX_EX_9_8,0x00},
    // //		{IMX477_TLPX_EX_7_0,0x3F},
    // //		{0xE04C,0x00},
    // //		{0xE04D,0x7F},
    // //		{0xE04E,0x00},
    // //		{0xE04F,0x1F},
    // //		{0x3E20,0x01},
    // //		{IMX477_PDAF_CTRL1_0,0x00},
    // //		{IMX477_POWER_SAVE_ENABLE,0x00},
    // //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    // //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    // //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    // //		{IMX477_MAP_COUP_CORR_EN,0x01},
    // //		{IMX477_SING_DEF_CORR_EN,0x01},
    // // {IMX477_GRP_PARAM_HOLD, 0x01},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x17},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0x70},
    // {IMX477_CIT_LSHIFT, 0x00},
    // // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // // {IMX477_GRP_PARAM_HOLD, 0x00},

    // //		{IMX477_FLASH_TRIG_RS,0x00},

    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    // //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},
    // //
    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    // //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    // //		{IMX477_LINE_LENGTH_PCK_15_8,0x17},
    // //		{IMX477_LINE_LENGTH_PCK_7_0,0x70},
    // //		{IMX477_CIT_LSHIFT,0x00},
    // //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    // //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},

    // //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    // //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    // //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    // {IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    // //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    // //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    // //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    // //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    // //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    // //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    // //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    // //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    // //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    // //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    // //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    // //		{IMX477_CKTESTSEL, 0x00},
    // //{0x0100,0x01}

};
/* Configuration settings for 676x504 RAW12*/
uint32_t RAW12_676x504_LINE_LENGTH_PCK = 0x5DBF;
I2CReg SENSOR_RAW12_676x504_ConfigurationSettings[] = {
    // {IMX477_CSI_DT_FMT_H, 0x08},
    // {IMX477_CSI_DT_FMT_L, 0x08},
    // //		{IMX477_CSI_LANE_MODE,0x01},
    // {IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x5D},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0xC0},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_X_ADD_STA_12_8, 0x00},
    // {IMX477_X_ADD_STA_7_0, 0x00},
    // {IMX477_Y_ADD_STA_12_8, 0x00},
    // {IMX477_Y_ADD_STA_7_0, 0x00},
    // {IMX477_X_ADD_END_12_8, 0x0F},
    // {IMX477_X_ADD_END_7_0, 0xD7},
    // {IMX477_Y_ADD_END_12_8, 0x0B},
    // {IMX477_Y_ADD_END_7_0, 0xCF},
    // //		{IMX477_DOL_EN_REGISTER,0x00},
    // //		{IMX477_DOL_NUM_REGISTER,0x00},
    // //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    // //		{IMX477_SME_HDR_MODE,0x00},
    // //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    // {IMX477_X_EVN_INC, 0x01},
    // {IMX477_X_ODD_INC, 0x01},
    // {IMX477_Y_EVN_INC, 0x01},
    // {IMX477_Y_ODD_INC, 0x03},
    // {IMX477_BINNING_MODE, 0x01},
    // {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x22},
    // {IMX477_BINNING_WEIGHTING, 0x02},
    // //		{0x3140,0x02},
    // //		{0x3C00,0x00},
    // //		{0x3C01,0x03},
    // //		{0x3C02,0xA2},
    // //		{0x3F0D,0x01},
    // //		{0x5748,0x07},
    // //		{0x5749,0xFF},
    // //		{0x574A,0x00},
    // //		{0x574B,0x00},
    // //		{0x7B75,0x0A},
    // //		{0x7B76,0x0C},
    // //		{0x7B77,0x07},
    // //		{0x7B78,0x06},
    // //		{0x7B79,0x3C},
    // //		{0x7B53,0x01},
    // //		{0x9369,0x5A},
    // //		{0x936B,0x55},
    // //		{0x936D,0x28},
    // //		{0x9304,0x00},
    // //		{0x9305,0x00},
    // //		{0x9E9A,0x2F},
    // //		{0x9E9B,0x2F},
    // //		{0x9E9C,0x2F},
    // //		{0x9E9D,0x00},
    // //		{0x9E9E,0x00},
    // //		{0x9E9F,0x00},
    // //		{0xA2A9,0x60},
    // //		{0xA2B7,0x00},
    // {IMX477_SCALE_MODE, 0x01},
    // {IMX477_SCALE_M_8, 0x00},
    // {IMX477_SCALE_M_7_0, 0x30},
    // {IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x07},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xEC},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x01},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xF8},
    // {IMX477_X_OUT_SIZE_12_8, 0x02},
    // {IMX477_X_OUT_SIZE_7_0, 0xA4},
    // {IMX477_Y_OUT_SIZE_12_8, 0x01},
    // {IMX477_Y_OUT_SIZE_7_0, 0xF8},
    // //		{IMX477_IVT_PXCK_DIV,0x05},
    // //		{IMX477_IVT_SYCK_DIV,0x02},
    // //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    // //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    // //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    // {IMX477_IOP_PXCK_DIV, 0x08},
    // //		{IMX477_IOP_SYCK_DIV,0x02},
    // //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    // //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    // //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    // //		{IMX477_PLL_MULT_DRIV,0x01},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    // //		{IMX477_TCLK_POST_EX_9_8,0x00},
    // //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    // //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    // //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    // //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    // //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    // //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    // //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    // //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    // //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    // //		{IMX477_TLPX_EX_9_8,0x00},
    // //		{IMX477_TLPX_EX_7_0,0x3F},
    // //		{0xE04C,0x00},
    // //		{0xE04D,0x7F},
    // //		{0xE04E,0x00},
    // //		{0xE04F,0x1F},
    // //		{0x3E20,0x01},
    // //		{IMX477_PDAF_CTRL1_0,0x00},
    // //		{IMX477_POWER_SAVE_ENABLE,0x00},
    // //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    // //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    // //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    // //		{IMX477_MAP_COUP_CORR_EN,0x01},
    // //		{IMX477_SING_DEF_CORR_EN,0x01},

    // // {IMX477_GRP_PARAM_HOLD, 0x01},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x5D},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0xBF},
    // {IMX477_CIT_LSHIFT, 0x00},
    // // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // // {IMX477_GRP_PARAM_HOLD, 0x00},

    // //		{IMX477_FLASH_TRIG_RS,0x00},

    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    // //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},
    // //
    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    // //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    // //		{IMX477_LINE_LENGTH_PCK_15_8,0x5D},
    // //		{IMX477_LINE_LENGTH_PCK_7_0,0xBF},
    // //		{IMX477_CIT_LSHIFT,0x00},
    // //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    // //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},

    // //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    // //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    // //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    // {IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_DISABLED},

    // //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    // //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    // //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    // //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    // //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    // //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    // //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    // //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    // //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    // //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    // //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    // //		{IMX477_CKTESTSEL, 0x00},
    // //{0x0100,0x01}
};
uint32_t RAW8_1352x760_LINE_LENGTH_PCK = 0x5DC0;
I2CReg SENSOR_RAW8_1352x760_ConfigurationSettings[] = {
    // {IMX477_CSI_DT_FMT_H, 0x08},
    // {IMX477_CSI_DT_FMT_L, 0x08},

    // {IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x5D},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0xC0},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_X_ADD_STA_12_8, 0x00},
    // {IMX477_X_ADD_STA_7_0, 0x00},
    // {IMX477_Y_ADD_STA_12_8, 0x00},
    // {IMX477_Y_ADD_STA_7_0, 0x00},
    // {IMX477_X_ADD_END_12_8, 0x0F},
    // {IMX477_X_ADD_END_7_0, 0xD7},
    // {IMX477_Y_ADD_END_12_8, 0x0B},
    // {IMX477_Y_ADD_END_7_0, 0xDF},
    // //		{IMX477_DOL_EN_REGISTER,0x00},
    // //		{IMX477_DOL_NUM_REGISTER,0x00},
    // //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    // //		{IMX477_SME_HDR_MODE,0x00},
    // //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    // {IMX477_X_EVN_INC, 0x01},
    // {IMX477_X_ODD_INC, 0x01},
    // {IMX477_Y_EVN_INC, 0x01},
    // {IMX477_Y_ODD_INC, 0x03},
    // {IMX477_BINNING_MODE, 0x01},
    // {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x22},
    // {IMX477_BINNING_WEIGHTING, 0x02},
    // //		{0x3140,0x02},
    // //		{0x3C00,0x00},
    // //		{0x3C01,0x03},
    // //		{0x3C02,0xA2},
    // //		{0x3F0D,0x01},
    // //		{0x5748,0x07},
    // //		{0x5749,0xFF},
    // //		{0x574A,0x00},
    // //		{0x574B,0x00},
    // //		{0x7B75,0x0A},
    // //		{0x7B76,0x0C},
    // //		{0x7B77,0x07},
    // //		{0x7B78,0x06},
    // //		{0x7B79,0x3C},
    // //		{0x7B53,0x01},
    // //		{0x9369,0x5A},
    // //		{0x936B,0x55},
    // //		{0x936D,0x28},
    // //		{0x9304,0x00},
    // //		{0x9305,0x00},
    // //		{0x9E9A,0x2F},
    // //		{0x9E9B,0x2F},
    // //		{0x9E9C,0x2F},
    // //		{0x9E9D,0x00},
    // //		{0x9E9E,0x00},
    // //		{0x9E9F,0x00},
    // //		{0xA2A9,0x60},
    // //		{0xA2B7,0x00},
    // {IMX477_SCALE_MODE, 0x01},
    // {IMX477_SCALE_M_8, 0x00},
    // {IMX477_SCALE_M_7_0, 0x18},
    // {IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x07},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xEC},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x02},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xF8},
    // {IMX477_X_OUT_SIZE_12_8, 0x05},
    // {IMX477_X_OUT_SIZE_7_0, 0x48},
    // {IMX477_Y_OUT_SIZE_12_8, 0x02},
    // {IMX477_Y_OUT_SIZE_7_0, 0xF8},
    // //		{IMX477_IVT_PXCK_DIV,0x05},
    // //		{IMX477_IVT_SYCK_DIV,0x02},
    // //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    // //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    // //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    // {IMX477_IOP_PXCK_DIV, 0x08},
    // //		{IMX477_IOP_SYCK_DIV,0x02},
    // //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    // //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    // //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    // //		{IMX477_PLL_MULT_DRIV,0x01},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    // //		{IMX477_TCLK_POST_EX_9_8,0x00},
    // //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    // //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    // //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    // //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    // //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    // //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    // //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    // //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    // //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    // //		{IMX477_TLPX_EX_9_8,0x00},
    // //		{IMX477_TLPX_EX_7_0,0x3F},
    // //		{0xE04C,0x00},
    // //		{0xE04D,0x7F},
    // //		{0xE04E,0x00},
    // //		{0xE04F,0x1F},
    // //		{0x3E20,0x01},
    // //		{IMX477_PDAF_CTRL1_0,0x00},
    // //		{IMX477_POWER_SAVE_ENABLE,0x00},
    // //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    // //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    // //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    // //		{IMX477_MAP_COUP_CORR_EN,0x01},
    // //		{IMX477_SING_DEF_CORR_EN,0x01},
    // // {IMX477_GRP_PARAM_HOLD, 0x01},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x5D},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0xC0},
    // {IMX477_CIT_LSHIFT, 0x00},
    // // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // // {IMX477_GRP_PARAM_HOLD, 0x00},

    // //		{IMX477_FLASH_TRIG_RS,0x00},

    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    // //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},
    // //
    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    // //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    // //		{IMX477_LINE_LENGTH_PCK_15_8,0x17},
    // //		{IMX477_LINE_LENGTH_PCK_7_0,0x70},
    // //		{IMX477_CIT_LSHIFT,0x00},
    // //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    // //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},

    // //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    // //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    // //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    // {IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    // //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    // //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    // //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    // //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    // //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    // //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    // //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    // //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    // //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    // //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    // //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    // //		{IMX477_CKTESTSEL, 0x00},
    // //{0x0100,0x01}
};
uint32_t RAW8_2028x1520_LINE_LENGTH_PCK = 0x5DC0;
I2CReg SENSOR_RAW8_2028x1520_ConfigurationSettings[] = {
    // {IMX477_CSI_DT_FMT_H, 0x08},
    // {IMX477_CSI_DT_FMT_L, 0x08},

    // {IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x5D},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0xC0},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_X_ADD_STA_12_8, 0x00},
    // {IMX477_X_ADD_STA_7_0, 0x00},
    // {IMX477_Y_ADD_STA_12_8, 0x00},
    // {IMX477_Y_ADD_STA_7_0, 0x00},
    // {IMX477_X_ADD_END_12_8, 0x0F},
    // {IMX477_X_ADD_END_7_0, 0xD7},
    // {IMX477_Y_ADD_END_12_8, 0x0B},
    // {IMX477_Y_ADD_END_7_0, 0xDF},
    // //		{IMX477_DOL_EN_REGISTER,0x00},
    // //		{IMX477_DOL_NUM_REGISTER,0x00},
    // //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    // //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    // //		{IMX477_SME_HDR_MODE,0x00},
    // //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    // {IMX477_X_EVN_INC, 0x01},
    // {IMX477_X_ODD_INC, 0x01},
    // {IMX477_Y_EVN_INC, 0x01},
    // {IMX477_Y_ODD_INC, 0x01},
    // {IMX477_BINNING_MODE, 0x01},
    // {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x22},
    // {IMX477_BINNING_WEIGHTING, 0x02},
    // //		{0x3140,0x02},
    // //		{0x3C00,0x00},
    // //		{0x3C01,0x03},
    // //		{0x3C02,0xA2},
    // //		{0x3F0D,0x01},
    // //		{0x5748,0x07},
    // //		{0x5749,0xFF},
    // //		{0x574A,0x00},
    // //		{0x574B,0x00},
    // //		{0x7B75,0x0A},
    // //		{0x7B76,0x0C},
    // //		{0x7B77,0x07},
    // //		{0x7B78,0x06},
    // //		{0x7B79,0x3C},
    // //		{0x7B53,0x01},
    // //		{0x9369,0x5A},
    // //		{0x936B,0x55},
    // //		{0x936D,0x28},
    // //		{0x9304,0x00},
    // //		{0x9305,0x00},
    // //		{0x9E9A,0x2F},
    // //		{0x9E9B,0x2F},
    // //		{0x9E9C,0x2F},
    // //		{0x9E9D,0x00},
    // //		{0x9E9E,0x00},
    // //		{0x9E9F,0x00},
    // //		{0xA2A9,0x60},
    // //		{0xA2B7,0x00},
    // {IMX477_SCALE_MODE, 0x00},
    // {IMX477_SCALE_M_8, 0x00},
    // {IMX477_SCALE_M_7_0, 0x10},
    // {IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    // {IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x07},
    // {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xEC},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x05},
    // {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xF0},
    // {IMX477_X_OUT_SIZE_12_8, 0x07},
    // {IMX477_X_OUT_SIZE_7_0, 0xEC},
    // {IMX477_Y_OUT_SIZE_12_8, 0x05},
    // {IMX477_Y_OUT_SIZE_7_0, 0xF0},
    // //		{IMX477_IVT_PXCK_DIV,0x05},
    // //		{IMX477_IVT_SYCK_DIV,0x02},
    // //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    // //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    // //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    // {IMX477_IOP_PXCK_DIV, 0x08},
    // //		{IMX477_IOP_SYCK_DIV,0x02},
    // //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    // //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    // //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    // //		{IMX477_PLL_MULT_DRIV,0x01},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    // //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    // //		{IMX477_TCLK_POST_EX_9_8,0x00},
    // //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    // //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    // //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    // //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    // //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    // //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    // //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    // //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    // //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    // //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    // //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    // //		{IMX477_TLPX_EX_9_8,0x00},
    // //		{IMX477_TLPX_EX_7_0,0x3F},
    // //		{0xE04C,0x00},
    // //		{0xE04D,0x7F},
    // //		{0xE04E,0x00},
    // //		{0xE04F,0x1F},
    // //		{0x3E20,0x01},
    // //		{IMX477_PDAF_CTRL1_0,0x00},
    // //		{IMX477_POWER_SAVE_ENABLE,0x00},
    // //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    // //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    // //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    // //		{IMX477_MAP_COUP_CORR_EN,0x01},
    // //		{IMX477_SING_DEF_CORR_EN,0x01},
    // // {IMX477_GRP_PARAM_HOLD, 0x01},
    // {IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    // {IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    // {IMX477_LINE_LENGTH_PCK_15_8, 0x5D},
    // {IMX477_LINE_LENGTH_PCK_7_0, 0xC0},
    // {IMX477_CIT_LSHIFT, 0x00},
    // // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // // {IMX477_GRP_PARAM_HOLD, 0x00},

    // //		{IMX477_FLASH_TRIG_RS,0x00},

    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    // //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},
    // //
    // //		{IMX477_GRP_PARAM_HOLD,0x01},
    // //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    // //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    // //		{IMX477_LINE_LENGTH_PCK_15_8,0x17},
    // //		{IMX477_LINE_LENGTH_PCK_7_0,0x70},
    // //		{IMX477_CIT_LSHIFT,0x00},
    // //		{IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // //		{IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // //		{IMX477_GRP_PARAM_HOLD,0x00},

    // //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    // //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    // //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    // {IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    // //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    // //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    // //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    // //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    // //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    // //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    // //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    // //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    // //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    // //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    // //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    // //		{IMX477_CKTESTSEL, 0x00},
    // //{0x0100,0x01}
};
uint32_t RAW8_1012x760_LINE_LENGTH_PCK = 0x1770;
I2CReg SENSOR_RAW8_1012x760_ConfigurationSettings[] = {
   ////{IMX477_CSI_DT_FMT_H, 0x08},
    ////{IMX477_CSI_DT_FMT_L, 0x08},

    ////{IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    {IMX477_LINE_LENGTH_PCK_15_8, 0x17},
    {IMX477_LINE_LENGTH_PCK_7_0, 0x70},
    ////{IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    ////{IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    ////{IMX477_X_ADD_STA_12_8, 0x00},
    ////{IMX477_X_ADD_STA_7_0, 0x00},
    ////{IMX477_Y_ADD_STA_12_8, 0x00},
    ////{IMX477_Y_ADD_STA_7_0, 0x00},
    ////{IMX477_X_ADD_END_12_8, 0x0F},
    ////{IMX477_X_ADD_END_7_0, 0xD7},
    ////{IMX477_Y_ADD_END_12_8, 0x0B},
    ////{IMX477_Y_ADD_END_7_0, 0xDF},
    //		{IMX477_DOL_EN_REGISTER,0x00},
    //		{IMX477_DOL_NUM_REGISTER,0x00},
    //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    //		{IMX477_SME_HDR_MODE,0x00},
    //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    ////{IMX477_X_EVN_INC, 0x01},
    ////{IMX477_X_ODD_INC, 0x01},
    ////{IMX477_Y_EVN_INC, 0x01},
    ////{IMX477_Y_ODD_INC, 0x01},
    {IMX477_BINNING_MODE, 0x01},
    {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x22},
    ////{IMX477_BINNING_WEIGHTING, 0x02},
    //		{0x3140,0x02},
    //		{0x3C00,0x00},
    //		{0x3C01,0x03},
    //		{0x3C02,0xA2},
    //		{0x3F0D,0x01},
    //		{0x5748,0x07},
    //		{0x5749,0xFF},
    //		{0x574A,0x00},
    //		{0x574B,0x00},
    //		{0x7B75,0x0A},
    //		{0x7B76,0x0C},
    //		{0x7B77,0x07},
    //		{0x7B78,0x06},
    //		{0x7B79,0x3C},
    //		{0x7B53,0x01},
    //		{0x9369,0x5A},
    //		{0x936B,0x55},
    //		{0x936D,0x28},
    //		{0x9304,0x00},
    //		{0x9305,0x00},
    //		{0x9E9A,0x2F},
    //		{0x9E9B,0x2F},
    //		{0x9E9C,0x2F},
    //		{0x9E9D,0x00},
    //		{0x9E9E,0x00},
    //		{0x9E9F,0x00},
    //		{0xA2A9,0x60},
    //		{0xA2B7,0x00},
    {IMX477_SCALE_MODE, 0x02},
    ////{IMX477_SCALE_M_8, 0x00},
    {IMX477_SCALE_M_7_0, 0x20},
    ////{IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    ////{IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    ////{IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    ////{IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x07},
    {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xEC},
    {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x05},
    {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xF0},
    {IMX477_X_OUT_SIZE_12_8, 0x03},
    {IMX477_X_OUT_SIZE_7_0, 0xF4},
    {IMX477_Y_OUT_SIZE_12_8, 0x02},
    {IMX477_Y_OUT_SIZE_7_0, 0xF8},
    //		{IMX477_IVT_PXCK_DIV,0x05},
    //		{IMX477_IVT_SYCK_DIV,0x02},
    //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    ////{IMX477_IOP_PXCK_DIV, 0x08},
    //		{IMX477_IOP_SYCK_DIV,0x02},
    //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    //		{IMX477_PLL_MULT_DRIV,0x01},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    //		{IMX477_TCLK_POST_EX_9_8,0x00},
    //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    //		{IMX477_TLPX_EX_9_8,0x00},
    //		{IMX477_TLPX_EX_7_0,0x3F},
    //		{0xE04C,0x00},
    //		{0xE04D,0x7F},
    //		{0xE04E,0x00},
    //		{0xE04F,0x1F},
    //		{0x3E20,0x01},
    //		{IMX477_PDAF_CTRL1_0,0x00},
    //		{IMX477_POWER_SAVE_ENABLE,0x00},
    //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    //		{IMX477_MAP_COUP_CORR_EN,0x01},
    //		{IMX477_SING_DEF_CORR_EN,0x01},
    // {IMX477_GRP_PARAM_HOLD, 0x01},
    ////{IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    ////{IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    {IMX477_LINE_LENGTH_PCK_15_8, 0x17},
    {IMX477_LINE_LENGTH_PCK_7_0, 0x70},
    ////{IMX477_CIT_LSHIFT, 0x00},
    // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // {IMX477_GRP_PARAM_HOLD, 0x00},

    //		{IMX477_FLASH_TRIG_RS,0x00},

    //		{IMX477_GRP_PARAM_HOLD,0x01},
    //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    //		{IMX477_GRP_PARAM_HOLD,0x00},
    //
    //		{IMX477_GRP_PARAM_HOLD,0x01},
    //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    //		{IMX477_LINE_LENGTH_PCK_15_8,0x17},
    //		{IMX477_LINE_LENGTH_PCK_7_0,0x70},
    //		{IMX477_CIT_LSHIFT,0x00},
    //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    //		{IMX477_GRP_PARAM_HOLD,0x00},

    //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    ////{IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    //		{IMX477_CKTESTSEL, 0x00},
    //{0x0100,0x01}
};
/*------------------------------------------------*/
I2CReg SENSOR_START_STREAM[] = {
    {IMX477_MODE_SEL,((IMX477_START_STREAM_VALUE)&0xFF)},

};
I2CReg SENSOR_STOP_STREAM[] = {
    {IMX477_MODE_SEL,((IMX477_STOP_STREAM_VALUE)&0xFF)},

};
I2CReg INCREASE_EXPOSURE[] = {
    {IMX477_COARSE_INTEG_TIME_15_8, 0x04},
    {IMX477_COARSE_INTEG_TIME_7_0, 0x60},
};


/*////{IMX477_CSI_DT_FMT_H, 0x08},
    ////{IMX477_CSI_DT_FMT_L, 0x08},

    ////{IMX477_FRM_LENGTH_CTL, IMX477_FRM_LENGTH_CTL_AUTOMATIC},
    {IMX477_LINE_LENGTH_PCK_15_8, 0x17},
    {IMX477_LINE_LENGTH_PCK_7_0, 0x70},
    ////{IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    ////{IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    ////{IMX477_X_ADD_STA_12_8, 0x00},
    ////{IMX477_X_ADD_STA_7_0, 0x00},
    ////{IMX477_Y_ADD_STA_12_8, 0x00},
    ////{IMX477_Y_ADD_STA_7_0, 0x00},
    ////{IMX477_X_ADD_END_12_8, 0x0F},
    ////{IMX477_X_ADD_END_7_0, 0xD7},
    ////{IMX477_Y_ADD_END_12_8, 0x0B},
    ////{IMX477_Y_ADD_END_7_0, 0xDF},
    //		{IMX477_DOL_EN_REGISTER,0x00},
    //		{IMX477_DOL_NUM_REGISTER,0x00},
    //		{IMX477_DOL_CSI_DT_FMT_H_2ND,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_L_2ND,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_H_3RD,0x0A},
    //		{IMX477_DOL_CSI_DT_FMT_L_3RD,0x0A},
    //		{IMX477_SME_HDR_MODE,0x00},
    //		{IMX477_SME_HDR_RESO_REDU_H_7_4_SME_HDR_RESO_REDU_V_3_0,0x11},
    ////{IMX477_X_EVN_INC, 0x01},
    ////{IMX477_X_ODD_INC, 0x01},
    ////{IMX477_Y_EVN_INC, 0x01},
    ////{IMX477_Y_ODD_INC, 0x01},
    {IMX477_BINNING_MODE, 0x01},
    {IMX477_BINNING_TYPE_H_7_4_BINNING_TYPE_V_3_0, 0x22},
    ////{IMX477_BINNING_WEIGHTING, 0x02},
    //		{0x3140,0x02},
    //		{0x3C00,0x00},
    //		{0x3C01,0x03},
    //		{0x3C02,0xA2},
    //		{0x3F0D,0x01},
    //		{0x5748,0x07},
    //		{0x5749,0xFF},
    //		{0x574A,0x00},
    //		{0x574B,0x00},
    //		{0x7B75,0x0A},
    //		{0x7B76,0x0C},
    //		{0x7B77,0x07},
    //		{0x7B78,0x06},
    //		{0x7B79,0x3C},
    //		{0x7B53,0x01},
    //		{0x9369,0x5A},
    //		{0x936B,0x55},
    //		{0x936D,0x28},
    //		{0x9304,0x00},
    //		{0x9305,0x00},
    //		{0x9E9A,0x2F},
    //		{0x9E9B,0x2F},
    //		{0x9E9C,0x2F},
    //		{0x9E9D,0x00},
    //		{0x9E9E,0x00},
    //		{0x9E9F,0x00},
    //		{0xA2A9,0x60},
    //		{0xA2B7,0x00},
    {IMX477_SCALE_MODE, 0x02},
    ////{IMX477_SCALE_M_8, 0x00},
    {IMX477_SCALE_M_7_0, 0x20},
    ////{IMX477_DIG_CROP_X_OFFSET_12_8, 0x00},
    ////{IMX477_DIG_CROP_X_OFFSET_7_0, 0x00},
    ////{IMX477_DIG_CROP_Y_OFFSET_12_8, 0x00},
    ////{IMX477_DIG_CROP_Y_OFFSET_7_0, 0x00},
    {IMX477_DIG_CROP_IMAGE_WIDTH_12_8, 0x07},
    {IMX477_DIG_CROP_IMAGE_WIDTH_7_0, 0xEC},
    {IMX477_DIG_CROP_IMAGE_HEIGHT_12_8, 0x05},
    {IMX477_DIG_CROP_IMAGE_HEIGHT_7_0, 0xF0},
    {IMX477_X_OUT_SIZE_12_8, 0x03},
    {IMX477_X_OUT_SIZE_7_0, 0xF4},
    {IMX477_Y_OUT_SIZE_12_8, 0x02},
    {IMX477_Y_OUT_SIZE_7_0, 0xF8},
    //		{IMX477_IVT_PXCK_DIV,0x05},
    //		{IMX477_IVT_SYCK_DIV,0x02},
    //		{IMX477_IVT_PREPLLCK_DIV,0x04},
    //		{IMX477_IVT_PLL_MPY_10_8,0x01},
    //		{IMX477_IVT_PLL_MPY_7_0,0x5E},
    ////{IMX477_IOP_PXCK_DIV, 0x08},
    //		{IMX477_IOP_SYCK_DIV,0x02},
    //		{IMX477_IOP_PREPLLCK_DIV,0x02},
    //		{IMX477_IOP_PLL_MPY_10_8,0x00},
    //		{IMX477_IOP_PLL_MPY_7_0,0x96},
    //		{IMX477_PLL_MULT_DRIV,0x01},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_31_24,0x07},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_23_16,0x08},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_15_8,0x00},
    //		{IMX477_REQ_LINK_BIT_RATE_MBPS_7_0,0x00},
    //		{IMX477_TCLK_POST_EX_9_8,0x00},
    //		{IMX477_TCLK_POST_EX_7_0,0x7F},
    //		{IMX477_THS_PREPARE_EX_9_8,0x00},
    //		{IMX477_THS_PREPARE_EX_7_0,0x4F},
    //		{IMX477_THS_ZERO_MIN_EX_9_8,0x00},
    //		{IMX477_THS_ZERO_MIN_EX_7_0,0x77},
    //		{IMX477_THS_TRAIL_EX_9_8,0x00},
    //		{IMX477_THS_TRAIL_EX_7_0,0x5F},
    //		{IMX477_TCLK_TRAIL_MIN_EX_9_8,0x00},
    //		{IMX477_TCLK_TRAIL_MIN_EX_7_0,0x57},
    //		{IMX477_TCLK_PREPARE_EX_9_8,0x00},
    //		{IMX477_TCLK_PREPARE_EX_7_0,0x4F},
    //		{IMX477_TCLK_ZERO_EX_9_8,0x01},
    //		{IMX477_TCLK_ZERO_EX_7_0,0x27},
    //		{IMX477_TLPX_EX_9_8,0x00},
    //		{IMX477_TLPX_EX_7_0,0x3F},
    //		{0xE04C,0x00},
    //		{0xE04D,0x7F},
    //		{0xE04E,0x00},
    //		{0xE04F,0x1F},
    //		{0x3E20,0x01},
    //		{IMX477_PDAF_CTRL1_0,0x00},
    //		{IMX477_POWER_SAVE_ENABLE,0x00},
    //		{IMX477_LINE_LENGTH_INCK_15_8,0x02},
    //		{IMX477_LINE_LENGTH_INCK_7_0,0xAE},
    //		{IMX477_IMG_ORIENTATION_V_H,0x00},
    //		{IMX477_MAP_COUP_CORR_EN,0x01},
    //		{IMX477_SING_DEF_CORR_EN,0x01},
    // {IMX477_GRP_PARAM_HOLD, 0x01},
    ////{IMX477_FRM_LENGTH_LINES_15_8, 0x0D},
    ////{IMX477_FRM_LENGTH_LINES_7_0, 0xAC},
    {IMX477_LINE_LENGTH_PCK_15_8, 0x17},
    {IMX477_LINE_LENGTH_PCK_7_0, 0x70},
    ////{IMX477_CIT_LSHIFT, 0x00},
    // {IMX477_COARSE_INTEG_TIME_15_8, 0x02},
    // {IMX477_COARSE_INTEG_TIME_7_0, 0xBC},
    // {IMX477_ANA_GAIN_GLOBAL_9_8, 0x00},
    // {IMX477_ANA_GAIN_GLOBAL_7_0, 0x00},
    // {IMX477_GRP_PARAM_HOLD, 0x00},

    //		{IMX477_FLASH_TRIG_RS,0x00},

    //		{IMX477_GRP_PARAM_HOLD,0x01},
    //		{IMX477_ANA_GAIN_GLOBAL_9_8,0x00},
    //		{IMX477_ANA_GAIN_GLOBAL_7_0,0x00},
    //		{IMX477_GRP_PARAM_HOLD,0x00},
    //
    //		{IMX477_GRP_PARAM_HOLD,0x01},
    //		{IMX477_FRM_LENGTH_LINES_15_8,0x0D},
    //		{IMX477_FRM_LENGTH_LINES_7_0,0xAC},
    //		{IMX477_LINE_LENGTH_PCK_15_8,0x17},
    //		{IMX477_LINE_LENGTH_PCK_7_0,0x70},
    //		{IMX477_CIT_LSHIFT,0x00},
    //		{IMX477_COARSE_INTEG_TIME_15_8,0x02},
    //		{IMX477_COARSE_INTEG_TIME_7_0,0xBC},
    //		{IMX477_GRP_PARAM_HOLD,0x00},

    //		{IMX477_DPGA_USE_GLOBAL_GAIN,0x00},

    //		{IMX477_COARSE_INTEG_TIME_15_8, 0x01},
    //		{IMX477_COARSE_INTEG_TIME_7_0, 0x00},

    ////{IMX477_EBD_SIZE_V_REGISTER, IMX477_EBD_SIZE_V_EMBEDDED_TWO_LINES},

    //		{IMX477_TESTMNT1, 0xfe}, // TESTMNT1,   FEh: XVS pin output signal is selected by MNTTEST2_SEL[8:0]
    //		{IMX477_TESTMNT2, 0xfd}, // TESTMNT2,   FDh: GPO pin output signal is selected by MNTTEST3_SEL[8:0]
    //		{IMX477_MNTTEST2_SEL_8, 0x00}, // MNTTEST2_SEL[8], 22d: V sync is selected.
    //		{IMX477_MNTTEST2_SEL_7_0, 0x16}, // MNTTEST2_SEL[7:0]
    //		{IMX477_MNTTEST3_SEL_8, 0x00}, // MNTTEST3_SEL[8], 21d: H sync is selected.
    //		{IMX477_MNTTEST3_SEL_7_0, 0x15}, // MNTTEST3_SEL[7:0]
    //		{IMX477_XVS_IO_CTRL, 0x01}, // XVS pin control, 1h: XVS pin : Output setting
    //		{IMX477_VSYNC_POL, 0x00}, // VSYNC_POL
    //		{IMX477_VSYNC_WID, 0x07}, // VSYNC_WID
    //		{IMX477_HSYNC_POL, 0x00}, // HSYNC_POL
    //		{IMX477_HSYNC_WID, 0x06}, // HSYNC_WID
    //		{IMX477_CKTESTSEL, 0x00},
    //{0x0100,0x01} */