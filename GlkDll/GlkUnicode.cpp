/////////////////////////////////////////////////////////////////////////////
//
// Windows MFC GLK Libraries
//
// GlkUnicode
// GLK Unicode case conversions, taken from Andrew Plotkin's CheapGlk
//
/////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstring>

#include "GlkUnicode.h"

typedef glui32 case_block_t[2];
typedef glui32 case_special_t[3];
typedef glui32 decomp_block_t[2];

case_block_t unigen_case_block_0x0[256] = {
  { 0x0, 0x0 },
  { 0x1, 0x1 },
  { 0x2, 0x2 },
  { 0x3, 0x3 },
  { 0x4, 0x4 },
  { 0x5, 0x5 },
  { 0x6, 0x6 },
  { 0x7, 0x7 },
  { 0x8, 0x8 },
  { 0x9, 0x9 },
  { 0xa, 0xa },
  { 0xb, 0xb },
  { 0xc, 0xc },
  { 0xd, 0xd },
  { 0xe, 0xe },
  { 0xf, 0xf },
  { 0x10, 0x10 },
  { 0x11, 0x11 },
  { 0x12, 0x12 },
  { 0x13, 0x13 },
  { 0x14, 0x14 },
  { 0x15, 0x15 },
  { 0x16, 0x16 },
  { 0x17, 0x17 },
  { 0x18, 0x18 },
  { 0x19, 0x19 },
  { 0x1a, 0x1a },
  { 0x1b, 0x1b },
  { 0x1c, 0x1c },
  { 0x1d, 0x1d },
  { 0x1e, 0x1e },
  { 0x1f, 0x1f },
  { 0x20, 0x20 },
  { 0x21, 0x21 },
  { 0x22, 0x22 },
  { 0x23, 0x23 },
  { 0x24, 0x24 },
  { 0x25, 0x25 },
  { 0x26, 0x26 },
  { 0x27, 0x27 },
  { 0x28, 0x28 },
  { 0x29, 0x29 },
  { 0x2a, 0x2a },
  { 0x2b, 0x2b },
  { 0x2c, 0x2c },
  { 0x2d, 0x2d },
  { 0x2e, 0x2e },
  { 0x2f, 0x2f },
  { 0x30, 0x30 },
  { 0x31, 0x31 },
  { 0x32, 0x32 },
  { 0x33, 0x33 },
  { 0x34, 0x34 },
  { 0x35, 0x35 },
  { 0x36, 0x36 },
  { 0x37, 0x37 },
  { 0x38, 0x38 },
  { 0x39, 0x39 },
  { 0x3a, 0x3a },
  { 0x3b, 0x3b },
  { 0x3c, 0x3c },
  { 0x3d, 0x3d },
  { 0x3e, 0x3e },
  { 0x3f, 0x3f },
  { 0x40, 0x40 },
  { 0x41, 0x61 },  /* upper */
  { 0x42, 0x62 },  /* upper */
  { 0x43, 0x63 },  /* upper */
  { 0x44, 0x64 },  /* upper */
  { 0x45, 0x65 },  /* upper */
  { 0x46, 0x66 },  /* upper */
  { 0x47, 0x67 },  /* upper */
  { 0x48, 0x68 },  /* upper */
  { 0x49, 0x69 },  /* upper */
  { 0x4a, 0x6a },  /* upper */
  { 0x4b, 0x6b },  /* upper */
  { 0x4c, 0x6c },  /* upper */
  { 0x4d, 0x6d },  /* upper */
  { 0x4e, 0x6e },  /* upper */
  { 0x4f, 0x6f },  /* upper */
  { 0x50, 0x70 },  /* upper */
  { 0x51, 0x71 },  /* upper */
  { 0x52, 0x72 },  /* upper */
  { 0x53, 0x73 },  /* upper */
  { 0x54, 0x74 },  /* upper */
  { 0x55, 0x75 },  /* upper */
  { 0x56, 0x76 },  /* upper */
  { 0x57, 0x77 },  /* upper */
  { 0x58, 0x78 },  /* upper */
  { 0x59, 0x79 },  /* upper */
  { 0x5a, 0x7a },  /* upper */
  { 0x5b, 0x5b },
  { 0x5c, 0x5c },
  { 0x5d, 0x5d },
  { 0x5e, 0x5e },
  { 0x5f, 0x5f },
  { 0x60, 0x60 },
  { 0x41, 0x61 },  /* lower */
  { 0x42, 0x62 },  /* lower */
  { 0x43, 0x63 },  /* lower */
  { 0x44, 0x64 },  /* lower */
  { 0x45, 0x65 },  /* lower */
  { 0x46, 0x66 },  /* lower */
  { 0x47, 0x67 },  /* lower */
  { 0x48, 0x68 },  /* lower */
  { 0x49, 0x69 },  /* lower */
  { 0x4a, 0x6a },  /* lower */
  { 0x4b, 0x6b },  /* lower */
  { 0x4c, 0x6c },  /* lower */
  { 0x4d, 0x6d },  /* lower */
  { 0x4e, 0x6e },  /* lower */
  { 0x4f, 0x6f },  /* lower */
  { 0x50, 0x70 },  /* lower */
  { 0x51, 0x71 },  /* lower */
  { 0x52, 0x72 },  /* lower */
  { 0x53, 0x73 },  /* lower */
  { 0x54, 0x74 },  /* lower */
  { 0x55, 0x75 },  /* lower */
  { 0x56, 0x76 },  /* lower */
  { 0x57, 0x77 },  /* lower */
  { 0x58, 0x78 },  /* lower */
  { 0x59, 0x79 },  /* lower */
  { 0x5a, 0x7a },  /* lower */
  { 0x7b, 0x7b },
  { 0x7c, 0x7c },
  { 0x7d, 0x7d },
  { 0x7e, 0x7e },
  { 0x7f, 0x7f },
  { 0x80, 0x80 },
  { 0x81, 0x81 },
  { 0x82, 0x82 },
  { 0x83, 0x83 },
  { 0x84, 0x84 },
  { 0x85, 0x85 },
  { 0x86, 0x86 },
  { 0x87, 0x87 },
  { 0x88, 0x88 },
  { 0x89, 0x89 },
  { 0x8a, 0x8a },
  { 0x8b, 0x8b },
  { 0x8c, 0x8c },
  { 0x8d, 0x8d },
  { 0x8e, 0x8e },
  { 0x8f, 0x8f },
  { 0x90, 0x90 },
  { 0x91, 0x91 },
  { 0x92, 0x92 },
  { 0x93, 0x93 },
  { 0x94, 0x94 },
  { 0x95, 0x95 },
  { 0x96, 0x96 },
  { 0x97, 0x97 },
  { 0x98, 0x98 },
  { 0x99, 0x99 },
  { 0x9a, 0x9a },
  { 0x9b, 0x9b },
  { 0x9c, 0x9c },
  { 0x9d, 0x9d },
  { 0x9e, 0x9e },
  { 0x9f, 0x9f },
  { 0xa0, 0xa0 },
  { 0xa1, 0xa1 },
  { 0xa2, 0xa2 },
  { 0xa3, 0xa3 },
  { 0xa4, 0xa4 },
  { 0xa5, 0xa5 },
  { 0xa6, 0xa6 },
  { 0xa7, 0xa7 },
  { 0xa8, 0xa8 },
  { 0xa9, 0xa9 },
  { 0xaa, 0xaa },
  { 0xab, 0xab },
  { 0xac, 0xac },
  { 0xad, 0xad },
  { 0xae, 0xae },
  { 0xaf, 0xaf },
  { 0xb0, 0xb0 },
  { 0xb1, 0xb1 },
  { 0xb2, 0xb2 },
  { 0xb3, 0xb3 },
  { 0xb4, 0xb4 },
  { 0x39c, 0xb5 },  /* lower */
  { 0xb6, 0xb6 },
  { 0xb7, 0xb7 },
  { 0xb8, 0xb8 },
  { 0xb9, 0xb9 },
  { 0xba, 0xba },
  { 0xbb, 0xbb },
  { 0xbc, 0xbc },
  { 0xbd, 0xbd },
  { 0xbe, 0xbe },
  { 0xbf, 0xbf },
  { 0xc0, 0xe0 },  /* upper */
  { 0xc1, 0xe1 },  /* upper */
  { 0xc2, 0xe2 },  /* upper */
  { 0xc3, 0xe3 },  /* upper */
  { 0xc4, 0xe4 },  /* upper */
  { 0xc5, 0xe5 },  /* upper */
  { 0xc6, 0xe6 },  /* upper */
  { 0xc7, 0xe7 },  /* upper */
  { 0xc8, 0xe8 },  /* upper */
  { 0xc9, 0xe9 },  /* upper */
  { 0xca, 0xea },  /* upper */
  { 0xcb, 0xeb },  /* upper */
  { 0xcc, 0xec },  /* upper */
  { 0xcd, 0xed },  /* upper */
  { 0xce, 0xee },  /* upper */
  { 0xcf, 0xef },  /* upper */
  { 0xd0, 0xf0 },  /* upper */
  { 0xd1, 0xf1 },  /* upper */
  { 0xd2, 0xf2 },  /* upper */
  { 0xd3, 0xf3 },  /* upper */
  { 0xd4, 0xf4 },  /* upper */
  { 0xd5, 0xf5 },  /* upper */
  { 0xd6, 0xf6 },  /* upper */
  { 0xd7, 0xd7 },
  { 0xd8, 0xf8 },  /* upper */
  { 0xd9, 0xf9 },  /* upper */
  { 0xda, 0xfa },  /* upper */
  { 0xdb, 0xfb },  /* upper */
  { 0xdc, 0xfc },  /* upper */
  { 0xdd, 0xfd },  /* upper */
  { 0xde, 0xfe },  /* upper */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xc0, 0xe0 },  /* lower */
  { 0xc1, 0xe1 },  /* lower */
  { 0xc2, 0xe2 },  /* lower */
  { 0xc3, 0xe3 },  /* lower */
  { 0xc4, 0xe4 },  /* lower */
  { 0xc5, 0xe5 },  /* lower */
  { 0xc6, 0xe6 },  /* lower */
  { 0xc7, 0xe7 },  /* lower */
  { 0xc8, 0xe8 },  /* lower */
  { 0xc9, 0xe9 },  /* lower */
  { 0xca, 0xea },  /* lower */
  { 0xcb, 0xeb },  /* lower */
  { 0xcc, 0xec },  /* lower */
  { 0xcd, 0xed },  /* lower */
  { 0xce, 0xee },  /* lower */
  { 0xcf, 0xef },  /* lower */
  { 0xd0, 0xf0 },  /* lower */
  { 0xd1, 0xf1 },  /* lower */
  { 0xd2, 0xf2 },  /* lower */
  { 0xd3, 0xf3 },  /* lower */
  { 0xd4, 0xf4 },  /* lower */
  { 0xd5, 0xf5 },  /* lower */
  { 0xd6, 0xf6 },  /* lower */
  { 0xf7, 0xf7 },
  { 0xd8, 0xf8 },  /* lower */
  { 0xd9, 0xf9 },  /* lower */
  { 0xda, 0xfa },  /* lower */
  { 0xdb, 0xfb },  /* lower */
  { 0xdc, 0xfc },  /* lower */
  { 0xdd, 0xfd },  /* lower */
  { 0xde, 0xfe },  /* lower */
  { 0x178, 0xff },  /* lower */
};

case_block_t unigen_case_block_0x1[256] = {
  { 0x100, 0x101 },  /* upper */
  { 0x100, 0x101 },  /* lower */
  { 0x102, 0x103 },  /* upper */
  { 0x102, 0x103 },  /* lower */
  { 0x104, 0x105 },  /* upper */
  { 0x104, 0x105 },  /* lower */
  { 0x106, 0x107 },  /* upper */
  { 0x106, 0x107 },  /* lower */
  { 0x108, 0x109 },  /* upper */
  { 0x108, 0x109 },  /* lower */
  { 0x10a, 0x10b },  /* upper */
  { 0x10a, 0x10b },  /* lower */
  { 0x10c, 0x10d },  /* upper */
  { 0x10c, 0x10d },  /* lower */
  { 0x10e, 0x10f },  /* upper */
  { 0x10e, 0x10f },  /* lower */
  { 0x110, 0x111 },  /* upper */
  { 0x110, 0x111 },  /* lower */
  { 0x112, 0x113 },  /* upper */
  { 0x112, 0x113 },  /* lower */
  { 0x114, 0x115 },  /* upper */
  { 0x114, 0x115 },  /* lower */
  { 0x116, 0x117 },  /* upper */
  { 0x116, 0x117 },  /* lower */
  { 0x118, 0x119 },  /* upper */
  { 0x118, 0x119 },  /* lower */
  { 0x11a, 0x11b },  /* upper */
  { 0x11a, 0x11b },  /* lower */
  { 0x11c, 0x11d },  /* upper */
  { 0x11c, 0x11d },  /* lower */
  { 0x11e, 0x11f },  /* upper */
  { 0x11e, 0x11f },  /* lower */
  { 0x120, 0x121 },  /* upper */
  { 0x120, 0x121 },  /* lower */
  { 0x122, 0x123 },  /* upper */
  { 0x122, 0x123 },  /* lower */
  { 0x124, 0x125 },  /* upper */
  { 0x124, 0x125 },  /* lower */
  { 0x126, 0x127 },  /* upper */
  { 0x126, 0x127 },  /* lower */
  { 0x128, 0x129 },  /* upper */
  { 0x128, 0x129 },  /* lower */
  { 0x12a, 0x12b },  /* upper */
  { 0x12a, 0x12b },  /* lower */
  { 0x12c, 0x12d },  /* upper */
  { 0x12c, 0x12d },  /* lower */
  { 0x12e, 0x12f },  /* upper */
  { 0x12e, 0x12f },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x49, 0x131 },  /* lower */
  { 0x132, 0x133 },  /* upper */
  { 0x132, 0x133 },  /* lower */
  { 0x134, 0x135 },  /* upper */
  { 0x134, 0x135 },  /* lower */
  { 0x136, 0x137 },  /* upper */
  { 0x136, 0x137 },  /* lower */
  { 0x138, 0x138 },
  { 0x139, 0x13a },  /* upper */
  { 0x139, 0x13a },  /* lower */
  { 0x13b, 0x13c },  /* upper */
  { 0x13b, 0x13c },  /* lower */
  { 0x13d, 0x13e },  /* upper */
  { 0x13d, 0x13e },  /* lower */
  { 0x13f, 0x140 },  /* upper */
  { 0x13f, 0x140 },  /* lower */
  { 0x141, 0x142 },  /* upper */
  { 0x141, 0x142 },  /* lower */
  { 0x143, 0x144 },  /* upper */
  { 0x143, 0x144 },  /* lower */
  { 0x145, 0x146 },  /* upper */
  { 0x145, 0x146 },  /* lower */
  { 0x147, 0x148 },  /* upper */
  { 0x147, 0x148 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x14a, 0x14b },  /* upper */
  { 0x14a, 0x14b },  /* lower */
  { 0x14c, 0x14d },  /* upper */
  { 0x14c, 0x14d },  /* lower */
  { 0x14e, 0x14f },  /* upper */
  { 0x14e, 0x14f },  /* lower */
  { 0x150, 0x151 },  /* upper */
  { 0x150, 0x151 },  /* lower */
  { 0x152, 0x153 },  /* upper */
  { 0x152, 0x153 },  /* lower */
  { 0x154, 0x155 },  /* upper */
  { 0x154, 0x155 },  /* lower */
  { 0x156, 0x157 },  /* upper */
  { 0x156, 0x157 },  /* lower */
  { 0x158, 0x159 },  /* upper */
  { 0x158, 0x159 },  /* lower */
  { 0x15a, 0x15b },  /* upper */
  { 0x15a, 0x15b },  /* lower */
  { 0x15c, 0x15d },  /* upper */
  { 0x15c, 0x15d },  /* lower */
  { 0x15e, 0x15f },  /* upper */
  { 0x15e, 0x15f },  /* lower */
  { 0x160, 0x161 },  /* upper */
  { 0x160, 0x161 },  /* lower */
  { 0x162, 0x163 },  /* upper */
  { 0x162, 0x163 },  /* lower */
  { 0x164, 0x165 },  /* upper */
  { 0x164, 0x165 },  /* lower */
  { 0x166, 0x167 },  /* upper */
  { 0x166, 0x167 },  /* lower */
  { 0x168, 0x169 },  /* upper */
  { 0x168, 0x169 },  /* lower */
  { 0x16a, 0x16b },  /* upper */
  { 0x16a, 0x16b },  /* lower */
  { 0x16c, 0x16d },  /* upper */
  { 0x16c, 0x16d },  /* lower */
  { 0x16e, 0x16f },  /* upper */
  { 0x16e, 0x16f },  /* lower */
  { 0x170, 0x171 },  /* upper */
  { 0x170, 0x171 },  /* lower */
  { 0x172, 0x173 },  /* upper */
  { 0x172, 0x173 },  /* lower */
  { 0x174, 0x175 },  /* upper */
  { 0x174, 0x175 },  /* lower */
  { 0x176, 0x177 },  /* upper */
  { 0x176, 0x177 },  /* lower */
  { 0x178, 0xff },  /* upper */
  { 0x179, 0x17a },  /* upper */
  { 0x179, 0x17a },  /* lower */
  { 0x17b, 0x17c },  /* upper */
  { 0x17b, 0x17c },  /* lower */
  { 0x17d, 0x17e },  /* upper */
  { 0x17d, 0x17e },  /* lower */
  { 0x53, 0x17f },  /* lower */
  { 0x180, 0x180 },
  { 0x181, 0x253 },  /* upper */
  { 0x182, 0x183 },  /* upper */
  { 0x182, 0x183 },  /* lower */
  { 0x184, 0x185 },  /* upper */
  { 0x184, 0x185 },  /* lower */
  { 0x186, 0x254 },  /* upper */
  { 0x187, 0x188 },  /* upper */
  { 0x187, 0x188 },  /* lower */
  { 0x189, 0x256 },  /* upper */
  { 0x18a, 0x257 },  /* upper */
  { 0x18b, 0x18c },  /* upper */
  { 0x18b, 0x18c },  /* lower */
  { 0x18d, 0x18d },
  { 0x18e, 0x1dd },  /* upper */
  { 0x18f, 0x259 },  /* upper */
  { 0x190, 0x25b },  /* upper */
  { 0x191, 0x192 },  /* upper */
  { 0x191, 0x192 },  /* lower */
  { 0x193, 0x260 },  /* upper */
  { 0x194, 0x263 },  /* upper */
  { 0x1f6, 0x195 },  /* lower */
  { 0x196, 0x269 },  /* upper */
  { 0x197, 0x268 },  /* upper */
  { 0x198, 0x199 },  /* upper */
  { 0x198, 0x199 },  /* lower */
  { 0x19a, 0x19a },
  { 0x19b, 0x19b },
  { 0x19c, 0x26f },  /* upper */
  { 0x19d, 0x272 },  /* upper */
  { 0x220, 0x19e },  /* lower */
  { 0x19f, 0x275 },  /* upper */
  { 0x1a0, 0x1a1 },  /* upper */
  { 0x1a0, 0x1a1 },  /* lower */
  { 0x1a2, 0x1a3 },  /* upper */
  { 0x1a2, 0x1a3 },  /* lower */
  { 0x1a4, 0x1a5 },  /* upper */
  { 0x1a4, 0x1a5 },  /* lower */
  { 0x1a6, 0x280 },  /* upper */
  { 0x1a7, 0x1a8 },  /* upper */
  { 0x1a7, 0x1a8 },  /* lower */
  { 0x1a9, 0x283 },  /* upper */
  { 0x1aa, 0x1aa },
  { 0x1ab, 0x1ab },
  { 0x1ac, 0x1ad },  /* upper */
  { 0x1ac, 0x1ad },  /* lower */
  { 0x1ae, 0x288 },  /* upper */
  { 0x1af, 0x1b0 },  /* upper */
  { 0x1af, 0x1b0 },  /* lower */
  { 0x1b1, 0x28a },  /* upper */
  { 0x1b2, 0x28b },  /* upper */
  { 0x1b3, 0x1b4 },  /* upper */
  { 0x1b3, 0x1b4 },  /* lower */
  { 0x1b5, 0x1b6 },  /* upper */
  { 0x1b5, 0x1b6 },  /* lower */
  { 0x1b7, 0x292 },  /* upper */
  { 0x1b8, 0x1b9 },  /* upper */
  { 0x1b8, 0x1b9 },  /* lower */
  { 0x1ba, 0x1ba },
  { 0x1bb, 0x1bb },
  { 0x1bc, 0x1bd },  /* upper */
  { 0x1bc, 0x1bd },  /* lower */
  { 0x1be, 0x1be },
  { 0x1f7, 0x1bf },  /* lower */
  { 0x1c0, 0x1c0 },
  { 0x1c1, 0x1c1 },
  { 0x1c2, 0x1c2 },
  { 0x1c3, 0x1c3 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1cd, 0x1ce },  /* upper */
  { 0x1cd, 0x1ce },  /* lower */
  { 0x1cf, 0x1d0 },  /* upper */
  { 0x1cf, 0x1d0 },  /* lower */
  { 0x1d1, 0x1d2 },  /* upper */
  { 0x1d1, 0x1d2 },  /* lower */
  { 0x1d3, 0x1d4 },  /* upper */
  { 0x1d3, 0x1d4 },  /* lower */
  { 0x1d5, 0x1d6 },  /* upper */
  { 0x1d5, 0x1d6 },  /* lower */
  { 0x1d7, 0x1d8 },  /* upper */
  { 0x1d7, 0x1d8 },  /* lower */
  { 0x1d9, 0x1da },  /* upper */
  { 0x1d9, 0x1da },  /* lower */
  { 0x1db, 0x1dc },  /* upper */
  { 0x1db, 0x1dc },  /* lower */
  { 0x18e, 0x1dd },  /* lower */
  { 0x1de, 0x1df },  /* upper */
  { 0x1de, 0x1df },  /* lower */
  { 0x1e0, 0x1e1 },  /* upper */
  { 0x1e0, 0x1e1 },  /* lower */
  { 0x1e2, 0x1e3 },  /* upper */
  { 0x1e2, 0x1e3 },  /* lower */
  { 0x1e4, 0x1e5 },  /* upper */
  { 0x1e4, 0x1e5 },  /* lower */
  { 0x1e6, 0x1e7 },  /* upper */
  { 0x1e6, 0x1e7 },  /* lower */
  { 0x1e8, 0x1e9 },  /* upper */
  { 0x1e8, 0x1e9 },  /* lower */
  { 0x1ea, 0x1eb },  /* upper */
  { 0x1ea, 0x1eb },  /* lower */
  { 0x1ec, 0x1ed },  /* upper */
  { 0x1ec, 0x1ed },  /* lower */
  { 0x1ee, 0x1ef },  /* upper */
  { 0x1ee, 0x1ef },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1f4, 0x1f5 },  /* upper */
  { 0x1f4, 0x1f5 },  /* lower */
  { 0x1f6, 0x195 },  /* upper */
  { 0x1f7, 0x1bf },  /* upper */
  { 0x1f8, 0x1f9 },  /* upper */
  { 0x1f8, 0x1f9 },  /* lower */
  { 0x1fa, 0x1fb },  /* upper */
  { 0x1fa, 0x1fb },  /* lower */
  { 0x1fc, 0x1fd },  /* upper */
  { 0x1fc, 0x1fd },  /* lower */
  { 0x1fe, 0x1ff },  /* upper */
  { 0x1fe, 0x1ff },  /* lower */
};

case_block_t unigen_case_block_0x2[256] = {
  { 0x200, 0x201 },  /* upper */
  { 0x200, 0x201 },  /* lower */
  { 0x202, 0x203 },  /* upper */
  { 0x202, 0x203 },  /* lower */
  { 0x204, 0x205 },  /* upper */
  { 0x204, 0x205 },  /* lower */
  { 0x206, 0x207 },  /* upper */
  { 0x206, 0x207 },  /* lower */
  { 0x208, 0x209 },  /* upper */
  { 0x208, 0x209 },  /* lower */
  { 0x20a, 0x20b },  /* upper */
  { 0x20a, 0x20b },  /* lower */
  { 0x20c, 0x20d },  /* upper */
  { 0x20c, 0x20d },  /* lower */
  { 0x20e, 0x20f },  /* upper */
  { 0x20e, 0x20f },  /* lower */
  { 0x210, 0x211 },  /* upper */
  { 0x210, 0x211 },  /* lower */
  { 0x212, 0x213 },  /* upper */
  { 0x212, 0x213 },  /* lower */
  { 0x214, 0x215 },  /* upper */
  { 0x214, 0x215 },  /* lower */
  { 0x216, 0x217 },  /* upper */
  { 0x216, 0x217 },  /* lower */
  { 0x218, 0x219 },  /* upper */
  { 0x218, 0x219 },  /* lower */
  { 0x21a, 0x21b },  /* upper */
  { 0x21a, 0x21b },  /* lower */
  { 0x21c, 0x21d },  /* upper */
  { 0x21c, 0x21d },  /* lower */
  { 0x21e, 0x21f },  /* upper */
  { 0x21e, 0x21f },  /* lower */
  { 0x220, 0x19e },  /* upper */
  { 0x221, 0x221 },
  { 0x222, 0x223 },  /* upper */
  { 0x222, 0x223 },  /* lower */
  { 0x224, 0x225 },  /* upper */
  { 0x224, 0x225 },  /* lower */
  { 0x226, 0x227 },  /* upper */
  { 0x226, 0x227 },  /* lower */
  { 0x228, 0x229 },  /* upper */
  { 0x228, 0x229 },  /* lower */
  { 0x22a, 0x22b },  /* upper */
  { 0x22a, 0x22b },  /* lower */
  { 0x22c, 0x22d },  /* upper */
  { 0x22c, 0x22d },  /* lower */
  { 0x22e, 0x22f },  /* upper */
  { 0x22e, 0x22f },  /* lower */
  { 0x230, 0x231 },  /* upper */
  { 0x230, 0x231 },  /* lower */
  { 0x232, 0x233 },  /* upper */
  { 0x232, 0x233 },  /* lower */
  { 0x234, 0x234 },
  { 0x235, 0x235 },
  { 0x236, 0x236 },
  { 0x237, 0x237 },
  { 0x238, 0x238 },
  { 0x239, 0x239 },
  { 0x23a, 0x23a },
  { 0x23b, 0x23b },
  { 0x23c, 0x23c },
  { 0x23d, 0x23d },
  { 0x23e, 0x23e },
  { 0x23f, 0x23f },
  { 0x240, 0x240 },
  { 0x241, 0x241 },
  { 0x242, 0x242 },
  { 0x243, 0x243 },
  { 0x244, 0x244 },
  { 0x245, 0x245 },
  { 0x246, 0x246 },
  { 0x247, 0x247 },
  { 0x248, 0x248 },
  { 0x249, 0x249 },
  { 0x24a, 0x24a },
  { 0x24b, 0x24b },
  { 0x24c, 0x24c },
  { 0x24d, 0x24d },
  { 0x24e, 0x24e },
  { 0x24f, 0x24f },
  { 0x250, 0x250 },
  { 0x251, 0x251 },
  { 0x252, 0x252 },
  { 0x181, 0x253 },  /* lower */
  { 0x186, 0x254 },  /* lower */
  { 0x255, 0x255 },
  { 0x189, 0x256 },  /* lower */
  { 0x18a, 0x257 },  /* lower */
  { 0x258, 0x258 },
  { 0x18f, 0x259 },  /* lower */
  { 0x25a, 0x25a },
  { 0x190, 0x25b },  /* lower */
  { 0x25c, 0x25c },
  { 0x25d, 0x25d },
  { 0x25e, 0x25e },
  { 0x25f, 0x25f },
  { 0x193, 0x260 },  /* lower */
  { 0x261, 0x261 },
  { 0x262, 0x262 },
  { 0x194, 0x263 },  /* lower */
  { 0x264, 0x264 },
  { 0x265, 0x265 },
  { 0x266, 0x266 },
  { 0x267, 0x267 },
  { 0x197, 0x268 },  /* lower */
  { 0x196, 0x269 },  /* lower */
  { 0x26a, 0x26a },
  { 0x26b, 0x26b },
  { 0x26c, 0x26c },
  { 0x26d, 0x26d },
  { 0x26e, 0x26e },
  { 0x19c, 0x26f },  /* lower */
  { 0x270, 0x270 },
  { 0x271, 0x271 },
  { 0x19d, 0x272 },  /* lower */
  { 0x273, 0x273 },
  { 0x274, 0x274 },
  { 0x19f, 0x275 },  /* lower */
  { 0x276, 0x276 },
  { 0x277, 0x277 },
  { 0x278, 0x278 },
  { 0x279, 0x279 },
  { 0x27a, 0x27a },
  { 0x27b, 0x27b },
  { 0x27c, 0x27c },
  { 0x27d, 0x27d },
  { 0x27e, 0x27e },
  { 0x27f, 0x27f },
  { 0x1a6, 0x280 },  /* lower */
  { 0x281, 0x281 },
  { 0x282, 0x282 },
  { 0x1a9, 0x283 },  /* lower */
  { 0x284, 0x284 },
  { 0x285, 0x285 },
  { 0x286, 0x286 },
  { 0x287, 0x287 },
  { 0x1ae, 0x288 },  /* lower */
  { 0x289, 0x289 },
  { 0x1b1, 0x28a },  /* lower */
  { 0x1b2, 0x28b },  /* lower */
  { 0x28c, 0x28c },
  { 0x28d, 0x28d },
  { 0x28e, 0x28e },
  { 0x28f, 0x28f },
  { 0x290, 0x290 },
  { 0x291, 0x291 },
  { 0x1b7, 0x292 },  /* lower */
  { 0x293, 0x293 },
  { 0x294, 0x294 },
  { 0x295, 0x295 },
  { 0x296, 0x296 },
  { 0x297, 0x297 },
  { 0x298, 0x298 },
  { 0x299, 0x299 },
  { 0x29a, 0x29a },
  { 0x29b, 0x29b },
  { 0x29c, 0x29c },
  { 0x29d, 0x29d },
  { 0x29e, 0x29e },
  { 0x29f, 0x29f },
  { 0x2a0, 0x2a0 },
  { 0x2a1, 0x2a1 },
  { 0x2a2, 0x2a2 },
  { 0x2a3, 0x2a3 },
  { 0x2a4, 0x2a4 },
  { 0x2a5, 0x2a5 },
  { 0x2a6, 0x2a6 },
  { 0x2a7, 0x2a7 },
  { 0x2a8, 0x2a8 },
  { 0x2a9, 0x2a9 },
  { 0x2aa, 0x2aa },
  { 0x2ab, 0x2ab },
  { 0x2ac, 0x2ac },
  { 0x2ad, 0x2ad },
  { 0x2ae, 0x2ae },
  { 0x2af, 0x2af },
  { 0x2b0, 0x2b0 },
  { 0x2b1, 0x2b1 },
  { 0x2b2, 0x2b2 },
  { 0x2b3, 0x2b3 },
  { 0x2b4, 0x2b4 },
  { 0x2b5, 0x2b5 },
  { 0x2b6, 0x2b6 },
  { 0x2b7, 0x2b7 },
  { 0x2b8, 0x2b8 },
  { 0x2b9, 0x2b9 },
  { 0x2ba, 0x2ba },
  { 0x2bb, 0x2bb },
  { 0x2bc, 0x2bc },
  { 0x2bd, 0x2bd },
  { 0x2be, 0x2be },
  { 0x2bf, 0x2bf },
  { 0x2c0, 0x2c0 },
  { 0x2c1, 0x2c1 },
  { 0x2c2, 0x2c2 },
  { 0x2c3, 0x2c3 },
  { 0x2c4, 0x2c4 },
  { 0x2c5, 0x2c5 },
  { 0x2c6, 0x2c6 },
  { 0x2c7, 0x2c7 },
  { 0x2c8, 0x2c8 },
  { 0x2c9, 0x2c9 },
  { 0x2ca, 0x2ca },
  { 0x2cb, 0x2cb },
  { 0x2cc, 0x2cc },
  { 0x2cd, 0x2cd },
  { 0x2ce, 0x2ce },
  { 0x2cf, 0x2cf },
  { 0x2d0, 0x2d0 },
  { 0x2d1, 0x2d1 },
  { 0x2d2, 0x2d2 },
  { 0x2d3, 0x2d3 },
  { 0x2d4, 0x2d4 },
  { 0x2d5, 0x2d5 },
  { 0x2d6, 0x2d6 },
  { 0x2d7, 0x2d7 },
  { 0x2d8, 0x2d8 },
  { 0x2d9, 0x2d9 },
  { 0x2da, 0x2da },
  { 0x2db, 0x2db },
  { 0x2dc, 0x2dc },
  { 0x2dd, 0x2dd },
  { 0x2de, 0x2de },
  { 0x2df, 0x2df },
  { 0x2e0, 0x2e0 },
  { 0x2e1, 0x2e1 },
  { 0x2e2, 0x2e2 },
  { 0x2e3, 0x2e3 },
  { 0x2e4, 0x2e4 },
  { 0x2e5, 0x2e5 },
  { 0x2e6, 0x2e6 },
  { 0x2e7, 0x2e7 },
  { 0x2e8, 0x2e8 },
  { 0x2e9, 0x2e9 },
  { 0x2ea, 0x2ea },
  { 0x2eb, 0x2eb },
  { 0x2ec, 0x2ec },
  { 0x2ed, 0x2ed },
  { 0x2ee, 0x2ee },
  { 0x2ef, 0x2ef },
  { 0x2f0, 0x2f0 },
  { 0x2f1, 0x2f1 },
  { 0x2f2, 0x2f2 },
  { 0x2f3, 0x2f3 },
  { 0x2f4, 0x2f4 },
  { 0x2f5, 0x2f5 },
  { 0x2f6, 0x2f6 },
  { 0x2f7, 0x2f7 },
  { 0x2f8, 0x2f8 },
  { 0x2f9, 0x2f9 },
  { 0x2fa, 0x2fa },
  { 0x2fb, 0x2fb },
  { 0x2fc, 0x2fc },
  { 0x2fd, 0x2fd },
  { 0x2fe, 0x2fe },
  { 0x2ff, 0x2ff },
};

case_block_t unigen_case_block_0x3[256] = {
  { 0x300, 0x300 },
  { 0x301, 0x301 },
  { 0x302, 0x302 },
  { 0x303, 0x303 },
  { 0x304, 0x304 },
  { 0x305, 0x305 },
  { 0x306, 0x306 },
  { 0x307, 0x307 },
  { 0x308, 0x308 },
  { 0x309, 0x309 },
  { 0x30a, 0x30a },
  { 0x30b, 0x30b },
  { 0x30c, 0x30c },
  { 0x30d, 0x30d },
  { 0x30e, 0x30e },
  { 0x30f, 0x30f },
  { 0x310, 0x310 },
  { 0x311, 0x311 },
  { 0x312, 0x312 },
  { 0x313, 0x313 },
  { 0x314, 0x314 },
  { 0x315, 0x315 },
  { 0x316, 0x316 },
  { 0x317, 0x317 },
  { 0x318, 0x318 },
  { 0x319, 0x319 },
  { 0x31a, 0x31a },
  { 0x31b, 0x31b },
  { 0x31c, 0x31c },
  { 0x31d, 0x31d },
  { 0x31e, 0x31e },
  { 0x31f, 0x31f },
  { 0x320, 0x320 },
  { 0x321, 0x321 },
  { 0x322, 0x322 },
  { 0x323, 0x323 },
  { 0x324, 0x324 },
  { 0x325, 0x325 },
  { 0x326, 0x326 },
  { 0x327, 0x327 },
  { 0x328, 0x328 },
  { 0x329, 0x329 },
  { 0x32a, 0x32a },
  { 0x32b, 0x32b },
  { 0x32c, 0x32c },
  { 0x32d, 0x32d },
  { 0x32e, 0x32e },
  { 0x32f, 0x32f },
  { 0x330, 0x330 },
  { 0x331, 0x331 },
  { 0x332, 0x332 },
  { 0x333, 0x333 },
  { 0x334, 0x334 },
  { 0x335, 0x335 },
  { 0x336, 0x336 },
  { 0x337, 0x337 },
  { 0x338, 0x338 },
  { 0x339, 0x339 },
  { 0x33a, 0x33a },
  { 0x33b, 0x33b },
  { 0x33c, 0x33c },
  { 0x33d, 0x33d },
  { 0x33e, 0x33e },
  { 0x33f, 0x33f },
  { 0x340, 0x340 },
  { 0x341, 0x341 },
  { 0x342, 0x342 },
  { 0x343, 0x343 },
  { 0x344, 0x344 },
  { 0x399, 0x345 },  /* lower */
  { 0x346, 0x346 },
  { 0x347, 0x347 },
  { 0x348, 0x348 },
  { 0x349, 0x349 },
  { 0x34a, 0x34a },
  { 0x34b, 0x34b },
  { 0x34c, 0x34c },
  { 0x34d, 0x34d },
  { 0x34e, 0x34e },
  { 0x34f, 0x34f },
  { 0x350, 0x350 },
  { 0x351, 0x351 },
  { 0x352, 0x352 },
  { 0x353, 0x353 },
  { 0x354, 0x354 },
  { 0x355, 0x355 },
  { 0x356, 0x356 },
  { 0x357, 0x357 },
  { 0x358, 0x358 },
  { 0x359, 0x359 },
  { 0x35a, 0x35a },
  { 0x35b, 0x35b },
  { 0x35c, 0x35c },
  { 0x35d, 0x35d },
  { 0x35e, 0x35e },
  { 0x35f, 0x35f },
  { 0x360, 0x360 },
  { 0x361, 0x361 },
  { 0x362, 0x362 },
  { 0x363, 0x363 },
  { 0x364, 0x364 },
  { 0x365, 0x365 },
  { 0x366, 0x366 },
  { 0x367, 0x367 },
  { 0x368, 0x368 },
  { 0x369, 0x369 },
  { 0x36a, 0x36a },
  { 0x36b, 0x36b },
  { 0x36c, 0x36c },
  { 0x36d, 0x36d },
  { 0x36e, 0x36e },
  { 0x36f, 0x36f },
  { 0x370, 0x370 },
  { 0x371, 0x371 },
  { 0x372, 0x372 },
  { 0x373, 0x373 },
  { 0x374, 0x374 },
  { 0x375, 0x375 },
  { 0x376, 0x376 },
  { 0x377, 0x377 },
  { 0x378, 0x378 },
  { 0x379, 0x379 },
  { 0x37a, 0x37a },
  { 0x37b, 0x37b },
  { 0x37c, 0x37c },
  { 0x37d, 0x37d },
  { 0x37e, 0x37e },
  { 0x37f, 0x37f },
  { 0x380, 0x380 },
  { 0x381, 0x381 },
  { 0x382, 0x382 },
  { 0x383, 0x383 },
  { 0x384, 0x384 },
  { 0x385, 0x385 },
  { 0x386, 0x3ac },  /* upper */
  { 0x387, 0x387 },
  { 0x388, 0x3ad },  /* upper */
  { 0x389, 0x3ae },  /* upper */
  { 0x38a, 0x3af },  /* upper */
  { 0x38b, 0x38b },
  { 0x38c, 0x3cc },  /* upper */
  { 0x38d, 0x38d },
  { 0x38e, 0x3cd },  /* upper */
  { 0x38f, 0x3ce },  /* upper */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x391, 0x3b1 },  /* upper */
  { 0x392, 0x3b2 },  /* upper */
  { 0x393, 0x3b3 },  /* upper */
  { 0x394, 0x3b4 },  /* upper */
  { 0x395, 0x3b5 },  /* upper */
  { 0x396, 0x3b6 },  /* upper */
  { 0x397, 0x3b7 },  /* upper */
  { 0x398, 0x3b8 },  /* upper */
  { 0x399, 0x3b9 },  /* upper */
  { 0x39a, 0x3ba },  /* upper */
  { 0x39b, 0x3bb },  /* upper */
  { 0x39c, 0x3bc },  /* upper */
  { 0x39d, 0x3bd },  /* upper */
  { 0x39e, 0x3be },  /* upper */
  { 0x39f, 0x3bf },  /* upper */
  { 0x3a0, 0x3c0 },  /* upper */
  { 0x3a1, 0x3c1 },  /* upper */
  { 0x3a2, 0x3a2 },
  { 0x3a3, 0x3c3 },  /* upper */
  { 0x3a4, 0x3c4 },  /* upper */
  { 0x3a5, 0x3c5 },  /* upper */
  { 0x3a6, 0x3c6 },  /* upper */
  { 0x3a7, 0x3c7 },  /* upper */
  { 0x3a8, 0x3c8 },  /* upper */
  { 0x3a9, 0x3c9 },  /* upper */
  { 0x3aa, 0x3ca },  /* upper */
  { 0x3ab, 0x3cb },  /* upper */
  { 0x386, 0x3ac },  /* lower */
  { 0x388, 0x3ad },  /* lower */
  { 0x389, 0x3ae },  /* lower */
  { 0x38a, 0x3af },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x391, 0x3b1 },  /* lower */
  { 0x392, 0x3b2 },  /* lower */
  { 0x393, 0x3b3 },  /* lower */
  { 0x394, 0x3b4 },  /* lower */
  { 0x395, 0x3b5 },  /* lower */
  { 0x396, 0x3b6 },  /* lower */
  { 0x397, 0x3b7 },  /* lower */
  { 0x398, 0x3b8 },  /* lower */
  { 0x399, 0x3b9 },  /* lower */
  { 0x39a, 0x3ba },  /* lower */
  { 0x39b, 0x3bb },  /* lower */
  { 0x39c, 0x3bc },  /* lower */
  { 0x39d, 0x3bd },  /* lower */
  { 0x39e, 0x3be },  /* lower */
  { 0x39f, 0x3bf },  /* lower */
  { 0x3a0, 0x3c0 },  /* lower */
  { 0x3a1, 0x3c1 },  /* lower */
  { 0x3a3, 0x3c2 },  /* lower */
  { 0x3a3, 0x3c3 },  /* lower */
  { 0x3a4, 0x3c4 },  /* lower */
  { 0x3a5, 0x3c5 },  /* lower */
  { 0x3a6, 0x3c6 },  /* lower */
  { 0x3a7, 0x3c7 },  /* lower */
  { 0x3a8, 0x3c8 },  /* lower */
  { 0x3a9, 0x3c9 },  /* lower */
  { 0x3aa, 0x3ca },  /* lower */
  { 0x3ab, 0x3cb },  /* lower */
  { 0x38c, 0x3cc },  /* lower */
  { 0x38e, 0x3cd },  /* lower */
  { 0x38f, 0x3ce },  /* lower */
  { 0x3cf, 0x3cf },
  { 0x392, 0x3d0 },  /* lower */
  { 0x398, 0x3d1 },  /* lower */
  { 0x3d2, 0x3d2 },
  { 0x3d3, 0x3d3 },
  { 0x3d4, 0x3d4 },
  { 0x3a6, 0x3d5 },  /* lower */
  { 0x3a0, 0x3d6 },  /* lower */
  { 0x3d7, 0x3d7 },
  { 0x3d8, 0x3d9 },  /* upper */
  { 0x3d8, 0x3d9 },  /* lower */
  { 0x3da, 0x3db },  /* upper */
  { 0x3da, 0x3db },  /* lower */
  { 0x3dc, 0x3dd },  /* upper */
  { 0x3dc, 0x3dd },  /* lower */
  { 0x3de, 0x3df },  /* upper */
  { 0x3de, 0x3df },  /* lower */
  { 0x3e0, 0x3e1 },  /* upper */
  { 0x3e0, 0x3e1 },  /* lower */
  { 0x3e2, 0x3e3 },  /* upper */
  { 0x3e2, 0x3e3 },  /* lower */
  { 0x3e4, 0x3e5 },  /* upper */
  { 0x3e4, 0x3e5 },  /* lower */
  { 0x3e6, 0x3e7 },  /* upper */
  { 0x3e6, 0x3e7 },  /* lower */
  { 0x3e8, 0x3e9 },  /* upper */
  { 0x3e8, 0x3e9 },  /* lower */
  { 0x3ea, 0x3eb },  /* upper */
  { 0x3ea, 0x3eb },  /* lower */
  { 0x3ec, 0x3ed },  /* upper */
  { 0x3ec, 0x3ed },  /* lower */
  { 0x3ee, 0x3ef },  /* upper */
  { 0x3ee, 0x3ef },  /* lower */
  { 0x39a, 0x3f0 },  /* lower */
  { 0x3a1, 0x3f1 },  /* lower */
  { 0x3f9, 0x3f2 },  /* lower */
  { 0x3f3, 0x3f3 },
  { 0x3f4, 0x3b8 },  /* upper */
  { 0x395, 0x3f5 },  /* lower */
  { 0x3f6, 0x3f6 },
  { 0x3f7, 0x3f8 },  /* upper */
  { 0x3f7, 0x3f8 },  /* lower */
  { 0x3f9, 0x3f2 },  /* upper */
  { 0x3fa, 0x3fb },  /* upper */
  { 0x3fa, 0x3fb },  /* lower */
  { 0x3fc, 0x3fc },
  { 0x3fd, 0x3fd },
  { 0x3fe, 0x3fe },
  { 0x3ff, 0x3ff },
};

case_block_t unigen_case_block_0x4[256] = {
  { 0x400, 0x450 },  /* upper */
  { 0x401, 0x451 },  /* upper */
  { 0x402, 0x452 },  /* upper */
  { 0x403, 0x453 },  /* upper */
  { 0x404, 0x454 },  /* upper */
  { 0x405, 0x455 },  /* upper */
  { 0x406, 0x456 },  /* upper */
  { 0x407, 0x457 },  /* upper */
  { 0x408, 0x458 },  /* upper */
  { 0x409, 0x459 },  /* upper */
  { 0x40a, 0x45a },  /* upper */
  { 0x40b, 0x45b },  /* upper */
  { 0x40c, 0x45c },  /* upper */
  { 0x40d, 0x45d },  /* upper */
  { 0x40e, 0x45e },  /* upper */
  { 0x40f, 0x45f },  /* upper */
  { 0x410, 0x430 },  /* upper */
  { 0x411, 0x431 },  /* upper */
  { 0x412, 0x432 },  /* upper */
  { 0x413, 0x433 },  /* upper */
  { 0x414, 0x434 },  /* upper */
  { 0x415, 0x435 },  /* upper */
  { 0x416, 0x436 },  /* upper */
  { 0x417, 0x437 },  /* upper */
  { 0x418, 0x438 },  /* upper */
  { 0x419, 0x439 },  /* upper */
  { 0x41a, 0x43a },  /* upper */
  { 0x41b, 0x43b },  /* upper */
  { 0x41c, 0x43c },  /* upper */
  { 0x41d, 0x43d },  /* upper */
  { 0x41e, 0x43e },  /* upper */
  { 0x41f, 0x43f },  /* upper */
  { 0x420, 0x440 },  /* upper */
  { 0x421, 0x441 },  /* upper */
  { 0x422, 0x442 },  /* upper */
  { 0x423, 0x443 },  /* upper */
  { 0x424, 0x444 },  /* upper */
  { 0x425, 0x445 },  /* upper */
  { 0x426, 0x446 },  /* upper */
  { 0x427, 0x447 },  /* upper */
  { 0x428, 0x448 },  /* upper */
  { 0x429, 0x449 },  /* upper */
  { 0x42a, 0x44a },  /* upper */
  { 0x42b, 0x44b },  /* upper */
  { 0x42c, 0x44c },  /* upper */
  { 0x42d, 0x44d },  /* upper */
  { 0x42e, 0x44e },  /* upper */
  { 0x42f, 0x44f },  /* upper */
  { 0x410, 0x430 },  /* lower */
  { 0x411, 0x431 },  /* lower */
  { 0x412, 0x432 },  /* lower */
  { 0x413, 0x433 },  /* lower */
  { 0x414, 0x434 },  /* lower */
  { 0x415, 0x435 },  /* lower */
  { 0x416, 0x436 },  /* lower */
  { 0x417, 0x437 },  /* lower */
  { 0x418, 0x438 },  /* lower */
  { 0x419, 0x439 },  /* lower */
  { 0x41a, 0x43a },  /* lower */
  { 0x41b, 0x43b },  /* lower */
  { 0x41c, 0x43c },  /* lower */
  { 0x41d, 0x43d },  /* lower */
  { 0x41e, 0x43e },  /* lower */
  { 0x41f, 0x43f },  /* lower */
  { 0x420, 0x440 },  /* lower */
  { 0x421, 0x441 },  /* lower */
  { 0x422, 0x442 },  /* lower */
  { 0x423, 0x443 },  /* lower */
  { 0x424, 0x444 },  /* lower */
  { 0x425, 0x445 },  /* lower */
  { 0x426, 0x446 },  /* lower */
  { 0x427, 0x447 },  /* lower */
  { 0x428, 0x448 },  /* lower */
  { 0x429, 0x449 },  /* lower */
  { 0x42a, 0x44a },  /* lower */
  { 0x42b, 0x44b },  /* lower */
  { 0x42c, 0x44c },  /* lower */
  { 0x42d, 0x44d },  /* lower */
  { 0x42e, 0x44e },  /* lower */
  { 0x42f, 0x44f },  /* lower */
  { 0x400, 0x450 },  /* lower */
  { 0x401, 0x451 },  /* lower */
  { 0x402, 0x452 },  /* lower */
  { 0x403, 0x453 },  /* lower */
  { 0x404, 0x454 },  /* lower */
  { 0x405, 0x455 },  /* lower */
  { 0x406, 0x456 },  /* lower */
  { 0x407, 0x457 },  /* lower */
  { 0x408, 0x458 },  /* lower */
  { 0x409, 0x459 },  /* lower */
  { 0x40a, 0x45a },  /* lower */
  { 0x40b, 0x45b },  /* lower */
  { 0x40c, 0x45c },  /* lower */
  { 0x40d, 0x45d },  /* lower */
  { 0x40e, 0x45e },  /* lower */
  { 0x40f, 0x45f },  /* lower */
  { 0x460, 0x461 },  /* upper */
  { 0x460, 0x461 },  /* lower */
  { 0x462, 0x463 },  /* upper */
  { 0x462, 0x463 },  /* lower */
  { 0x464, 0x465 },  /* upper */
  { 0x464, 0x465 },  /* lower */
  { 0x466, 0x467 },  /* upper */
  { 0x466, 0x467 },  /* lower */
  { 0x468, 0x469 },  /* upper */
  { 0x468, 0x469 },  /* lower */
  { 0x46a, 0x46b },  /* upper */
  { 0x46a, 0x46b },  /* lower */
  { 0x46c, 0x46d },  /* upper */
  { 0x46c, 0x46d },  /* lower */
  { 0x46e, 0x46f },  /* upper */
  { 0x46e, 0x46f },  /* lower */
  { 0x470, 0x471 },  /* upper */
  { 0x470, 0x471 },  /* lower */
  { 0x472, 0x473 },  /* upper */
  { 0x472, 0x473 },  /* lower */
  { 0x474, 0x475 },  /* upper */
  { 0x474, 0x475 },  /* lower */
  { 0x476, 0x477 },  /* upper */
  { 0x476, 0x477 },  /* lower */
  { 0x478, 0x479 },  /* upper */
  { 0x478, 0x479 },  /* lower */
  { 0x47a, 0x47b },  /* upper */
  { 0x47a, 0x47b },  /* lower */
  { 0x47c, 0x47d },  /* upper */
  { 0x47c, 0x47d },  /* lower */
  { 0x47e, 0x47f },  /* upper */
  { 0x47e, 0x47f },  /* lower */
  { 0x480, 0x481 },  /* upper */
  { 0x480, 0x481 },  /* lower */
  { 0x482, 0x482 },
  { 0x483, 0x483 },
  { 0x484, 0x484 },
  { 0x485, 0x485 },
  { 0x486, 0x486 },
  { 0x487, 0x487 },
  { 0x488, 0x488 },
  { 0x489, 0x489 },
  { 0x48a, 0x48b },  /* upper */
  { 0x48a, 0x48b },  /* lower */
  { 0x48c, 0x48d },  /* upper */
  { 0x48c, 0x48d },  /* lower */
  { 0x48e, 0x48f },  /* upper */
  { 0x48e, 0x48f },  /* lower */
  { 0x490, 0x491 },  /* upper */
  { 0x490, 0x491 },  /* lower */
  { 0x492, 0x493 },  /* upper */
  { 0x492, 0x493 },  /* lower */
  { 0x494, 0x495 },  /* upper */
  { 0x494, 0x495 },  /* lower */
  { 0x496, 0x497 },  /* upper */
  { 0x496, 0x497 },  /* lower */
  { 0x498, 0x499 },  /* upper */
  { 0x498, 0x499 },  /* lower */
  { 0x49a, 0x49b },  /* upper */
  { 0x49a, 0x49b },  /* lower */
  { 0x49c, 0x49d },  /* upper */
  { 0x49c, 0x49d },  /* lower */
  { 0x49e, 0x49f },  /* upper */
  { 0x49e, 0x49f },  /* lower */
  { 0x4a0, 0x4a1 },  /* upper */
  { 0x4a0, 0x4a1 },  /* lower */
  { 0x4a2, 0x4a3 },  /* upper */
  { 0x4a2, 0x4a3 },  /* lower */
  { 0x4a4, 0x4a5 },  /* upper */
  { 0x4a4, 0x4a5 },  /* lower */
  { 0x4a6, 0x4a7 },  /* upper */
  { 0x4a6, 0x4a7 },  /* lower */
  { 0x4a8, 0x4a9 },  /* upper */
  { 0x4a8, 0x4a9 },  /* lower */
  { 0x4aa, 0x4ab },  /* upper */
  { 0x4aa, 0x4ab },  /* lower */
  { 0x4ac, 0x4ad },  /* upper */
  { 0x4ac, 0x4ad },  /* lower */
  { 0x4ae, 0x4af },  /* upper */
  { 0x4ae, 0x4af },  /* lower */
  { 0x4b0, 0x4b1 },  /* upper */
  { 0x4b0, 0x4b1 },  /* lower */
  { 0x4b2, 0x4b3 },  /* upper */
  { 0x4b2, 0x4b3 },  /* lower */
  { 0x4b4, 0x4b5 },  /* upper */
  { 0x4b4, 0x4b5 },  /* lower */
  { 0x4b6, 0x4b7 },  /* upper */
  { 0x4b6, 0x4b7 },  /* lower */
  { 0x4b8, 0x4b9 },  /* upper */
  { 0x4b8, 0x4b9 },  /* lower */
  { 0x4ba, 0x4bb },  /* upper */
  { 0x4ba, 0x4bb },  /* lower */
  { 0x4bc, 0x4bd },  /* upper */
  { 0x4bc, 0x4bd },  /* lower */
  { 0x4be, 0x4bf },  /* upper */
  { 0x4be, 0x4bf },  /* lower */
  { 0x4c0, 0x4c0 },
  { 0x4c1, 0x4c2 },  /* upper */
  { 0x4c1, 0x4c2 },  /* lower */
  { 0x4c3, 0x4c4 },  /* upper */
  { 0x4c3, 0x4c4 },  /* lower */
  { 0x4c5, 0x4c6 },  /* upper */
  { 0x4c5, 0x4c6 },  /* lower */
  { 0x4c7, 0x4c8 },  /* upper */
  { 0x4c7, 0x4c8 },  /* lower */
  { 0x4c9, 0x4ca },  /* upper */
  { 0x4c9, 0x4ca },  /* lower */
  { 0x4cb, 0x4cc },  /* upper */
  { 0x4cb, 0x4cc },  /* lower */
  { 0x4cd, 0x4ce },  /* upper */
  { 0x4cd, 0x4ce },  /* lower */
  { 0x4cf, 0x4cf },
  { 0x4d0, 0x4d1 },  /* upper */
  { 0x4d0, 0x4d1 },  /* lower */
  { 0x4d2, 0x4d3 },  /* upper */
  { 0x4d2, 0x4d3 },  /* lower */
  { 0x4d4, 0x4d5 },  /* upper */
  { 0x4d4, 0x4d5 },  /* lower */
  { 0x4d6, 0x4d7 },  /* upper */
  { 0x4d6, 0x4d7 },  /* lower */
  { 0x4d8, 0x4d9 },  /* upper */
  { 0x4d8, 0x4d9 },  /* lower */
  { 0x4da, 0x4db },  /* upper */
  { 0x4da, 0x4db },  /* lower */
  { 0x4dc, 0x4dd },  /* upper */
  { 0x4dc, 0x4dd },  /* lower */
  { 0x4de, 0x4df },  /* upper */
  { 0x4de, 0x4df },  /* lower */
  { 0x4e0, 0x4e1 },  /* upper */
  { 0x4e0, 0x4e1 },  /* lower */
  { 0x4e2, 0x4e3 },  /* upper */
  { 0x4e2, 0x4e3 },  /* lower */
  { 0x4e4, 0x4e5 },  /* upper */
  { 0x4e4, 0x4e5 },  /* lower */
  { 0x4e6, 0x4e7 },  /* upper */
  { 0x4e6, 0x4e7 },  /* lower */
  { 0x4e8, 0x4e9 },  /* upper */
  { 0x4e8, 0x4e9 },  /* lower */
  { 0x4ea, 0x4eb },  /* upper */
  { 0x4ea, 0x4eb },  /* lower */
  { 0x4ec, 0x4ed },  /* upper */
  { 0x4ec, 0x4ed },  /* lower */
  { 0x4ee, 0x4ef },  /* upper */
  { 0x4ee, 0x4ef },  /* lower */
  { 0x4f0, 0x4f1 },  /* upper */
  { 0x4f0, 0x4f1 },  /* lower */
  { 0x4f2, 0x4f3 },  /* upper */
  { 0x4f2, 0x4f3 },  /* lower */
  { 0x4f4, 0x4f5 },  /* upper */
  { 0x4f4, 0x4f5 },  /* lower */
  { 0x4f6, 0x4f6 },
  { 0x4f7, 0x4f7 },
  { 0x4f8, 0x4f9 },  /* upper */
  { 0x4f8, 0x4f9 },  /* lower */
  { 0x4fa, 0x4fa },
  { 0x4fb, 0x4fb },
  { 0x4fc, 0x4fc },
  { 0x4fd, 0x4fd },
  { 0x4fe, 0x4fe },
  { 0x4ff, 0x4ff },
};

case_block_t unigen_case_block_0x5[256] = {
  { 0x500, 0x501 },  /* upper */
  { 0x500, 0x501 },  /* lower */
  { 0x502, 0x503 },  /* upper */
  { 0x502, 0x503 },  /* lower */
  { 0x504, 0x505 },  /* upper */
  { 0x504, 0x505 },  /* lower */
  { 0x506, 0x507 },  /* upper */
  { 0x506, 0x507 },  /* lower */
  { 0x508, 0x509 },  /* upper */
  { 0x508, 0x509 },  /* lower */
  { 0x50a, 0x50b },  /* upper */
  { 0x50a, 0x50b },  /* lower */
  { 0x50c, 0x50d },  /* upper */
  { 0x50c, 0x50d },  /* lower */
  { 0x50e, 0x50f },  /* upper */
  { 0x50e, 0x50f },  /* lower */
  { 0x510, 0x510 },
  { 0x511, 0x511 },
  { 0x512, 0x512 },
  { 0x513, 0x513 },
  { 0x514, 0x514 },
  { 0x515, 0x515 },
  { 0x516, 0x516 },
  { 0x517, 0x517 },
  { 0x518, 0x518 },
  { 0x519, 0x519 },
  { 0x51a, 0x51a },
  { 0x51b, 0x51b },
  { 0x51c, 0x51c },
  { 0x51d, 0x51d },
  { 0x51e, 0x51e },
  { 0x51f, 0x51f },
  { 0x520, 0x520 },
  { 0x521, 0x521 },
  { 0x522, 0x522 },
  { 0x523, 0x523 },
  { 0x524, 0x524 },
  { 0x525, 0x525 },
  { 0x526, 0x526 },
  { 0x527, 0x527 },
  { 0x528, 0x528 },
  { 0x529, 0x529 },
  { 0x52a, 0x52a },
  { 0x52b, 0x52b },
  { 0x52c, 0x52c },
  { 0x52d, 0x52d },
  { 0x52e, 0x52e },
  { 0x52f, 0x52f },
  { 0x530, 0x530 },
  { 0x531, 0x561 },  /* upper */
  { 0x532, 0x562 },  /* upper */
  { 0x533, 0x563 },  /* upper */
  { 0x534, 0x564 },  /* upper */
  { 0x535, 0x565 },  /* upper */
  { 0x536, 0x566 },  /* upper */
  { 0x537, 0x567 },  /* upper */
  { 0x538, 0x568 },  /* upper */
  { 0x539, 0x569 },  /* upper */
  { 0x53a, 0x56a },  /* upper */
  { 0x53b, 0x56b },  /* upper */
  { 0x53c, 0x56c },  /* upper */
  { 0x53d, 0x56d },  /* upper */
  { 0x53e, 0x56e },  /* upper */
  { 0x53f, 0x56f },  /* upper */
  { 0x540, 0x570 },  /* upper */
  { 0x541, 0x571 },  /* upper */
  { 0x542, 0x572 },  /* upper */
  { 0x543, 0x573 },  /* upper */
  { 0x544, 0x574 },  /* upper */
  { 0x545, 0x575 },  /* upper */
  { 0x546, 0x576 },  /* upper */
  { 0x547, 0x577 },  /* upper */
  { 0x548, 0x578 },  /* upper */
  { 0x549, 0x579 },  /* upper */
  { 0x54a, 0x57a },  /* upper */
  { 0x54b, 0x57b },  /* upper */
  { 0x54c, 0x57c },  /* upper */
  { 0x54d, 0x57d },  /* upper */
  { 0x54e, 0x57e },  /* upper */
  { 0x54f, 0x57f },  /* upper */
  { 0x550, 0x580 },  /* upper */
  { 0x551, 0x581 },  /* upper */
  { 0x552, 0x582 },  /* upper */
  { 0x553, 0x583 },  /* upper */
  { 0x554, 0x584 },  /* upper */
  { 0x555, 0x585 },  /* upper */
  { 0x556, 0x586 },  /* upper */
  { 0x557, 0x557 },
  { 0x558, 0x558 },
  { 0x559, 0x559 },
  { 0x55a, 0x55a },
  { 0x55b, 0x55b },
  { 0x55c, 0x55c },
  { 0x55d, 0x55d },
  { 0x55e, 0x55e },
  { 0x55f, 0x55f },
  { 0x560, 0x560 },
  { 0x531, 0x561 },  /* lower */
  { 0x532, 0x562 },  /* lower */
  { 0x533, 0x563 },  /* lower */
  { 0x534, 0x564 },  /* lower */
  { 0x535, 0x565 },  /* lower */
  { 0x536, 0x566 },  /* lower */
  { 0x537, 0x567 },  /* lower */
  { 0x538, 0x568 },  /* lower */
  { 0x539, 0x569 },  /* lower */
  { 0x53a, 0x56a },  /* lower */
  { 0x53b, 0x56b },  /* lower */
  { 0x53c, 0x56c },  /* lower */
  { 0x53d, 0x56d },  /* lower */
  { 0x53e, 0x56e },  /* lower */
  { 0x53f, 0x56f },  /* lower */
  { 0x540, 0x570 },  /* lower */
  { 0x541, 0x571 },  /* lower */
  { 0x542, 0x572 },  /* lower */
  { 0x543, 0x573 },  /* lower */
  { 0x544, 0x574 },  /* lower */
  { 0x545, 0x575 },  /* lower */
  { 0x546, 0x576 },  /* lower */
  { 0x547, 0x577 },  /* lower */
  { 0x548, 0x578 },  /* lower */
  { 0x549, 0x579 },  /* lower */
  { 0x54a, 0x57a },  /* lower */
  { 0x54b, 0x57b },  /* lower */
  { 0x54c, 0x57c },  /* lower */
  { 0x54d, 0x57d },  /* lower */
  { 0x54e, 0x57e },  /* lower */
  { 0x54f, 0x57f },  /* lower */
  { 0x550, 0x580 },  /* lower */
  { 0x551, 0x581 },  /* lower */
  { 0x552, 0x582 },  /* lower */
  { 0x553, 0x583 },  /* lower */
  { 0x554, 0x584 },  /* lower */
  { 0x555, 0x585 },  /* lower */
  { 0x556, 0x586 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x588, 0x588 },
  { 0x589, 0x589 },
  { 0x58a, 0x58a },
  { 0x58b, 0x58b },
  { 0x58c, 0x58c },
  { 0x58d, 0x58d },
  { 0x58e, 0x58e },
  { 0x58f, 0x58f },
  { 0x590, 0x590 },
  { 0x591, 0x591 },
  { 0x592, 0x592 },
  { 0x593, 0x593 },
  { 0x594, 0x594 },
  { 0x595, 0x595 },
  { 0x596, 0x596 },
  { 0x597, 0x597 },
  { 0x598, 0x598 },
  { 0x599, 0x599 },
  { 0x59a, 0x59a },
  { 0x59b, 0x59b },
  { 0x59c, 0x59c },
  { 0x59d, 0x59d },
  { 0x59e, 0x59e },
  { 0x59f, 0x59f },
  { 0x5a0, 0x5a0 },
  { 0x5a1, 0x5a1 },
  { 0x5a2, 0x5a2 },
  { 0x5a3, 0x5a3 },
  { 0x5a4, 0x5a4 },
  { 0x5a5, 0x5a5 },
  { 0x5a6, 0x5a6 },
  { 0x5a7, 0x5a7 },
  { 0x5a8, 0x5a8 },
  { 0x5a9, 0x5a9 },
  { 0x5aa, 0x5aa },
  { 0x5ab, 0x5ab },
  { 0x5ac, 0x5ac },
  { 0x5ad, 0x5ad },
  { 0x5ae, 0x5ae },
  { 0x5af, 0x5af },
  { 0x5b0, 0x5b0 },
  { 0x5b1, 0x5b1 },
  { 0x5b2, 0x5b2 },
  { 0x5b3, 0x5b3 },
  { 0x5b4, 0x5b4 },
  { 0x5b5, 0x5b5 },
  { 0x5b6, 0x5b6 },
  { 0x5b7, 0x5b7 },
  { 0x5b8, 0x5b8 },
  { 0x5b9, 0x5b9 },
  { 0x5ba, 0x5ba },
  { 0x5bb, 0x5bb },
  { 0x5bc, 0x5bc },
  { 0x5bd, 0x5bd },
  { 0x5be, 0x5be },
  { 0x5bf, 0x5bf },
  { 0x5c0, 0x5c0 },
  { 0x5c1, 0x5c1 },
  { 0x5c2, 0x5c2 },
  { 0x5c3, 0x5c3 },
  { 0x5c4, 0x5c4 },
  { 0x5c5, 0x5c5 },
  { 0x5c6, 0x5c6 },
  { 0x5c7, 0x5c7 },
  { 0x5c8, 0x5c8 },
  { 0x5c9, 0x5c9 },
  { 0x5ca, 0x5ca },
  { 0x5cb, 0x5cb },
  { 0x5cc, 0x5cc },
  { 0x5cd, 0x5cd },
  { 0x5ce, 0x5ce },
  { 0x5cf, 0x5cf },
  { 0x5d0, 0x5d0 },
  { 0x5d1, 0x5d1 },
  { 0x5d2, 0x5d2 },
  { 0x5d3, 0x5d3 },
  { 0x5d4, 0x5d4 },
  { 0x5d5, 0x5d5 },
  { 0x5d6, 0x5d6 },
  { 0x5d7, 0x5d7 },
  { 0x5d8, 0x5d8 },
  { 0x5d9, 0x5d9 },
  { 0x5da, 0x5da },
  { 0x5db, 0x5db },
  { 0x5dc, 0x5dc },
  { 0x5dd, 0x5dd },
  { 0x5de, 0x5de },
  { 0x5df, 0x5df },
  { 0x5e0, 0x5e0 },
  { 0x5e1, 0x5e1 },
  { 0x5e2, 0x5e2 },
  { 0x5e3, 0x5e3 },
  { 0x5e4, 0x5e4 },
  { 0x5e5, 0x5e5 },
  { 0x5e6, 0x5e6 },
  { 0x5e7, 0x5e7 },
  { 0x5e8, 0x5e8 },
  { 0x5e9, 0x5e9 },
  { 0x5ea, 0x5ea },
  { 0x5eb, 0x5eb },
  { 0x5ec, 0x5ec },
  { 0x5ed, 0x5ed },
  { 0x5ee, 0x5ee },
  { 0x5ef, 0x5ef },
  { 0x5f0, 0x5f0 },
  { 0x5f1, 0x5f1 },
  { 0x5f2, 0x5f2 },
  { 0x5f3, 0x5f3 },
  { 0x5f4, 0x5f4 },
  { 0x5f5, 0x5f5 },
  { 0x5f6, 0x5f6 },
  { 0x5f7, 0x5f7 },
  { 0x5f8, 0x5f8 },
  { 0x5f9, 0x5f9 },
  { 0x5fa, 0x5fa },
  { 0x5fb, 0x5fb },
  { 0x5fc, 0x5fc },
  { 0x5fd, 0x5fd },
  { 0x5fe, 0x5fe },
  { 0x5ff, 0x5ff },
};

case_block_t unigen_case_block_0x1e[256] = {
  { 0x1e00, 0x1e01 },  /* upper */
  { 0x1e00, 0x1e01 },  /* lower */
  { 0x1e02, 0x1e03 },  /* upper */
  { 0x1e02, 0x1e03 },  /* lower */
  { 0x1e04, 0x1e05 },  /* upper */
  { 0x1e04, 0x1e05 },  /* lower */
  { 0x1e06, 0x1e07 },  /* upper */
  { 0x1e06, 0x1e07 },  /* lower */
  { 0x1e08, 0x1e09 },  /* upper */
  { 0x1e08, 0x1e09 },  /* lower */
  { 0x1e0a, 0x1e0b },  /* upper */
  { 0x1e0a, 0x1e0b },  /* lower */
  { 0x1e0c, 0x1e0d },  /* upper */
  { 0x1e0c, 0x1e0d },  /* lower */
  { 0x1e0e, 0x1e0f },  /* upper */
  { 0x1e0e, 0x1e0f },  /* lower */
  { 0x1e10, 0x1e11 },  /* upper */
  { 0x1e10, 0x1e11 },  /* lower */
  { 0x1e12, 0x1e13 },  /* upper */
  { 0x1e12, 0x1e13 },  /* lower */
  { 0x1e14, 0x1e15 },  /* upper */
  { 0x1e14, 0x1e15 },  /* lower */
  { 0x1e16, 0x1e17 },  /* upper */
  { 0x1e16, 0x1e17 },  /* lower */
  { 0x1e18, 0x1e19 },  /* upper */
  { 0x1e18, 0x1e19 },  /* lower */
  { 0x1e1a, 0x1e1b },  /* upper */
  { 0x1e1a, 0x1e1b },  /* lower */
  { 0x1e1c, 0x1e1d },  /* upper */
  { 0x1e1c, 0x1e1d },  /* lower */
  { 0x1e1e, 0x1e1f },  /* upper */
  { 0x1e1e, 0x1e1f },  /* lower */
  { 0x1e20, 0x1e21 },  /* upper */
  { 0x1e20, 0x1e21 },  /* lower */
  { 0x1e22, 0x1e23 },  /* upper */
  { 0x1e22, 0x1e23 },  /* lower */
  { 0x1e24, 0x1e25 },  /* upper */
  { 0x1e24, 0x1e25 },  /* lower */
  { 0x1e26, 0x1e27 },  /* upper */
  { 0x1e26, 0x1e27 },  /* lower */
  { 0x1e28, 0x1e29 },  /* upper */
  { 0x1e28, 0x1e29 },  /* lower */
  { 0x1e2a, 0x1e2b },  /* upper */
  { 0x1e2a, 0x1e2b },  /* lower */
  { 0x1e2c, 0x1e2d },  /* upper */
  { 0x1e2c, 0x1e2d },  /* lower */
  { 0x1e2e, 0x1e2f },  /* upper */
  { 0x1e2e, 0x1e2f },  /* lower */
  { 0x1e30, 0x1e31 },  /* upper */
  { 0x1e30, 0x1e31 },  /* lower */
  { 0x1e32, 0x1e33 },  /* upper */
  { 0x1e32, 0x1e33 },  /* lower */
  { 0x1e34, 0x1e35 },  /* upper */
  { 0x1e34, 0x1e35 },  /* lower */
  { 0x1e36, 0x1e37 },  /* upper */
  { 0x1e36, 0x1e37 },  /* lower */
  { 0x1e38, 0x1e39 },  /* upper */
  { 0x1e38, 0x1e39 },  /* lower */
  { 0x1e3a, 0x1e3b },  /* upper */
  { 0x1e3a, 0x1e3b },  /* lower */
  { 0x1e3c, 0x1e3d },  /* upper */
  { 0x1e3c, 0x1e3d },  /* lower */
  { 0x1e3e, 0x1e3f },  /* upper */
  { 0x1e3e, 0x1e3f },  /* lower */
  { 0x1e40, 0x1e41 },  /* upper */
  { 0x1e40, 0x1e41 },  /* lower */
  { 0x1e42, 0x1e43 },  /* upper */
  { 0x1e42, 0x1e43 },  /* lower */
  { 0x1e44, 0x1e45 },  /* upper */
  { 0x1e44, 0x1e45 },  /* lower */
  { 0x1e46, 0x1e47 },  /* upper */
  { 0x1e46, 0x1e47 },  /* lower */
  { 0x1e48, 0x1e49 },  /* upper */
  { 0x1e48, 0x1e49 },  /* lower */
  { 0x1e4a, 0x1e4b },  /* upper */
  { 0x1e4a, 0x1e4b },  /* lower */
  { 0x1e4c, 0x1e4d },  /* upper */
  { 0x1e4c, 0x1e4d },  /* lower */
  { 0x1e4e, 0x1e4f },  /* upper */
  { 0x1e4e, 0x1e4f },  /* lower */
  { 0x1e50, 0x1e51 },  /* upper */
  { 0x1e50, 0x1e51 },  /* lower */
  { 0x1e52, 0x1e53 },  /* upper */
  { 0x1e52, 0x1e53 },  /* lower */
  { 0x1e54, 0x1e55 },  /* upper */
  { 0x1e54, 0x1e55 },  /* lower */
  { 0x1e56, 0x1e57 },  /* upper */
  { 0x1e56, 0x1e57 },  /* lower */
  { 0x1e58, 0x1e59 },  /* upper */
  { 0x1e58, 0x1e59 },  /* lower */
  { 0x1e5a, 0x1e5b },  /* upper */
  { 0x1e5a, 0x1e5b },  /* lower */
  { 0x1e5c, 0x1e5d },  /* upper */
  { 0x1e5c, 0x1e5d },  /* lower */
  { 0x1e5e, 0x1e5f },  /* upper */
  { 0x1e5e, 0x1e5f },  /* lower */
  { 0x1e60, 0x1e61 },  /* upper */
  { 0x1e60, 0x1e61 },  /* lower */
  { 0x1e62, 0x1e63 },  /* upper */
  { 0x1e62, 0x1e63 },  /* lower */
  { 0x1e64, 0x1e65 },  /* upper */
  { 0x1e64, 0x1e65 },  /* lower */
  { 0x1e66, 0x1e67 },  /* upper */
  { 0x1e66, 0x1e67 },  /* lower */
  { 0x1e68, 0x1e69 },  /* upper */
  { 0x1e68, 0x1e69 },  /* lower */
  { 0x1e6a, 0x1e6b },  /* upper */
  { 0x1e6a, 0x1e6b },  /* lower */
  { 0x1e6c, 0x1e6d },  /* upper */
  { 0x1e6c, 0x1e6d },  /* lower */
  { 0x1e6e, 0x1e6f },  /* upper */
  { 0x1e6e, 0x1e6f },  /* lower */
  { 0x1e70, 0x1e71 },  /* upper */
  { 0x1e70, 0x1e71 },  /* lower */
  { 0x1e72, 0x1e73 },  /* upper */
  { 0x1e72, 0x1e73 },  /* lower */
  { 0x1e74, 0x1e75 },  /* upper */
  { 0x1e74, 0x1e75 },  /* lower */
  { 0x1e76, 0x1e77 },  /* upper */
  { 0x1e76, 0x1e77 },  /* lower */
  { 0x1e78, 0x1e79 },  /* upper */
  { 0x1e78, 0x1e79 },  /* lower */
  { 0x1e7a, 0x1e7b },  /* upper */
  { 0x1e7a, 0x1e7b },  /* lower */
  { 0x1e7c, 0x1e7d },  /* upper */
  { 0x1e7c, 0x1e7d },  /* lower */
  { 0x1e7e, 0x1e7f },  /* upper */
  { 0x1e7e, 0x1e7f },  /* lower */
  { 0x1e80, 0x1e81 },  /* upper */
  { 0x1e80, 0x1e81 },  /* lower */
  { 0x1e82, 0x1e83 },  /* upper */
  { 0x1e82, 0x1e83 },  /* lower */
  { 0x1e84, 0x1e85 },  /* upper */
  { 0x1e84, 0x1e85 },  /* lower */
  { 0x1e86, 0x1e87 },  /* upper */
  { 0x1e86, 0x1e87 },  /* lower */
  { 0x1e88, 0x1e89 },  /* upper */
  { 0x1e88, 0x1e89 },  /* lower */
  { 0x1e8a, 0x1e8b },  /* upper */
  { 0x1e8a, 0x1e8b },  /* lower */
  { 0x1e8c, 0x1e8d },  /* upper */
  { 0x1e8c, 0x1e8d },  /* lower */
  { 0x1e8e, 0x1e8f },  /* upper */
  { 0x1e8e, 0x1e8f },  /* lower */
  { 0x1e90, 0x1e91 },  /* upper */
  { 0x1e90, 0x1e91 },  /* lower */
  { 0x1e92, 0x1e93 },  /* upper */
  { 0x1e92, 0x1e93 },  /* lower */
  { 0x1e94, 0x1e95 },  /* upper */
  { 0x1e94, 0x1e95 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1e60, 0x1e9b },  /* lower */
  { 0x1e9c, 0x1e9c },
  { 0x1e9d, 0x1e9d },
  { 0x1e9e, 0x1e9e },
  { 0x1e9f, 0x1e9f },
  { 0x1ea0, 0x1ea1 },  /* upper */
  { 0x1ea0, 0x1ea1 },  /* lower */
  { 0x1ea2, 0x1ea3 },  /* upper */
  { 0x1ea2, 0x1ea3 },  /* lower */
  { 0x1ea4, 0x1ea5 },  /* upper */
  { 0x1ea4, 0x1ea5 },  /* lower */
  { 0x1ea6, 0x1ea7 },  /* upper */
  { 0x1ea6, 0x1ea7 },  /* lower */
  { 0x1ea8, 0x1ea9 },  /* upper */
  { 0x1ea8, 0x1ea9 },  /* lower */
  { 0x1eaa, 0x1eab },  /* upper */
  { 0x1eaa, 0x1eab },  /* lower */
  { 0x1eac, 0x1ead },  /* upper */
  { 0x1eac, 0x1ead },  /* lower */
  { 0x1eae, 0x1eaf },  /* upper */
  { 0x1eae, 0x1eaf },  /* lower */
  { 0x1eb0, 0x1eb1 },  /* upper */
  { 0x1eb0, 0x1eb1 },  /* lower */
  { 0x1eb2, 0x1eb3 },  /* upper */
  { 0x1eb2, 0x1eb3 },  /* lower */
  { 0x1eb4, 0x1eb5 },  /* upper */
  { 0x1eb4, 0x1eb5 },  /* lower */
  { 0x1eb6, 0x1eb7 },  /* upper */
  { 0x1eb6, 0x1eb7 },  /* lower */
  { 0x1eb8, 0x1eb9 },  /* upper */
  { 0x1eb8, 0x1eb9 },  /* lower */
  { 0x1eba, 0x1ebb },  /* upper */
  { 0x1eba, 0x1ebb },  /* lower */
  { 0x1ebc, 0x1ebd },  /* upper */
  { 0x1ebc, 0x1ebd },  /* lower */
  { 0x1ebe, 0x1ebf },  /* upper */
  { 0x1ebe, 0x1ebf },  /* lower */
  { 0x1ec0, 0x1ec1 },  /* upper */
  { 0x1ec0, 0x1ec1 },  /* lower */
  { 0x1ec2, 0x1ec3 },  /* upper */
  { 0x1ec2, 0x1ec3 },  /* lower */
  { 0x1ec4, 0x1ec5 },  /* upper */
  { 0x1ec4, 0x1ec5 },  /* lower */
  { 0x1ec6, 0x1ec7 },  /* upper */
  { 0x1ec6, 0x1ec7 },  /* lower */
  { 0x1ec8, 0x1ec9 },  /* upper */
  { 0x1ec8, 0x1ec9 },  /* lower */
  { 0x1eca, 0x1ecb },  /* upper */
  { 0x1eca, 0x1ecb },  /* lower */
  { 0x1ecc, 0x1ecd },  /* upper */
  { 0x1ecc, 0x1ecd },  /* lower */
  { 0x1ece, 0x1ecf },  /* upper */
  { 0x1ece, 0x1ecf },  /* lower */
  { 0x1ed0, 0x1ed1 },  /* upper */
  { 0x1ed0, 0x1ed1 },  /* lower */
  { 0x1ed2, 0x1ed3 },  /* upper */
  { 0x1ed2, 0x1ed3 },  /* lower */
  { 0x1ed4, 0x1ed5 },  /* upper */
  { 0x1ed4, 0x1ed5 },  /* lower */
  { 0x1ed6, 0x1ed7 },  /* upper */
  { 0x1ed6, 0x1ed7 },  /* lower */
  { 0x1ed8, 0x1ed9 },  /* upper */
  { 0x1ed8, 0x1ed9 },  /* lower */
  { 0x1eda, 0x1edb },  /* upper */
  { 0x1eda, 0x1edb },  /* lower */
  { 0x1edc, 0x1edd },  /* upper */
  { 0x1edc, 0x1edd },  /* lower */
  { 0x1ede, 0x1edf },  /* upper */
  { 0x1ede, 0x1edf },  /* lower */
  { 0x1ee0, 0x1ee1 },  /* upper */
  { 0x1ee0, 0x1ee1 },  /* lower */
  { 0x1ee2, 0x1ee3 },  /* upper */
  { 0x1ee2, 0x1ee3 },  /* lower */
  { 0x1ee4, 0x1ee5 },  /* upper */
  { 0x1ee4, 0x1ee5 },  /* lower */
  { 0x1ee6, 0x1ee7 },  /* upper */
  { 0x1ee6, 0x1ee7 },  /* lower */
  { 0x1ee8, 0x1ee9 },  /* upper */
  { 0x1ee8, 0x1ee9 },  /* lower */
  { 0x1eea, 0x1eeb },  /* upper */
  { 0x1eea, 0x1eeb },  /* lower */
  { 0x1eec, 0x1eed },  /* upper */
  { 0x1eec, 0x1eed },  /* lower */
  { 0x1eee, 0x1eef },  /* upper */
  { 0x1eee, 0x1eef },  /* lower */
  { 0x1ef0, 0x1ef1 },  /* upper */
  { 0x1ef0, 0x1ef1 },  /* lower */
  { 0x1ef2, 0x1ef3 },  /* upper */
  { 0x1ef2, 0x1ef3 },  /* lower */
  { 0x1ef4, 0x1ef5 },  /* upper */
  { 0x1ef4, 0x1ef5 },  /* lower */
  { 0x1ef6, 0x1ef7 },  /* upper */
  { 0x1ef6, 0x1ef7 },  /* lower */
  { 0x1ef8, 0x1ef9 },  /* upper */
  { 0x1ef8, 0x1ef9 },  /* lower */
  { 0x1efa, 0x1efa },
  { 0x1efb, 0x1efb },
  { 0x1efc, 0x1efc },
  { 0x1efd, 0x1efd },
  { 0x1efe, 0x1efe },
  { 0x1eff, 0x1eff },
};

case_block_t unigen_case_block_0x1f[256] = {
  { 0x1f08, 0x1f00 },  /* lower */
  { 0x1f09, 0x1f01 },  /* lower */
  { 0x1f0a, 0x1f02 },  /* lower */
  { 0x1f0b, 0x1f03 },  /* lower */
  { 0x1f0c, 0x1f04 },  /* lower */
  { 0x1f0d, 0x1f05 },  /* lower */
  { 0x1f0e, 0x1f06 },  /* lower */
  { 0x1f0f, 0x1f07 },  /* lower */
  { 0x1f08, 0x1f00 },  /* upper */
  { 0x1f09, 0x1f01 },  /* upper */
  { 0x1f0a, 0x1f02 },  /* upper */
  { 0x1f0b, 0x1f03 },  /* upper */
  { 0x1f0c, 0x1f04 },  /* upper */
  { 0x1f0d, 0x1f05 },  /* upper */
  { 0x1f0e, 0x1f06 },  /* upper */
  { 0x1f0f, 0x1f07 },  /* upper */
  { 0x1f18, 0x1f10 },  /* lower */
  { 0x1f19, 0x1f11 },  /* lower */
  { 0x1f1a, 0x1f12 },  /* lower */
  { 0x1f1b, 0x1f13 },  /* lower */
  { 0x1f1c, 0x1f14 },  /* lower */
  { 0x1f1d, 0x1f15 },  /* lower */
  { 0x1f16, 0x1f16 },
  { 0x1f17, 0x1f17 },
  { 0x1f18, 0x1f10 },  /* upper */
  { 0x1f19, 0x1f11 },  /* upper */
  { 0x1f1a, 0x1f12 },  /* upper */
  { 0x1f1b, 0x1f13 },  /* upper */
  { 0x1f1c, 0x1f14 },  /* upper */
  { 0x1f1d, 0x1f15 },  /* upper */
  { 0x1f1e, 0x1f1e },
  { 0x1f1f, 0x1f1f },
  { 0x1f28, 0x1f20 },  /* lower */
  { 0x1f29, 0x1f21 },  /* lower */
  { 0x1f2a, 0x1f22 },  /* lower */
  { 0x1f2b, 0x1f23 },  /* lower */
  { 0x1f2c, 0x1f24 },  /* lower */
  { 0x1f2d, 0x1f25 },  /* lower */
  { 0x1f2e, 0x1f26 },  /* lower */
  { 0x1f2f, 0x1f27 },  /* lower */
  { 0x1f28, 0x1f20 },  /* upper */
  { 0x1f29, 0x1f21 },  /* upper */
  { 0x1f2a, 0x1f22 },  /* upper */
  { 0x1f2b, 0x1f23 },  /* upper */
  { 0x1f2c, 0x1f24 },  /* upper */
  { 0x1f2d, 0x1f25 },  /* upper */
  { 0x1f2e, 0x1f26 },  /* upper */
  { 0x1f2f, 0x1f27 },  /* upper */
  { 0x1f38, 0x1f30 },  /* lower */
  { 0x1f39, 0x1f31 },  /* lower */
  { 0x1f3a, 0x1f32 },  /* lower */
  { 0x1f3b, 0x1f33 },  /* lower */
  { 0x1f3c, 0x1f34 },  /* lower */
  { 0x1f3d, 0x1f35 },  /* lower */
  { 0x1f3e, 0x1f36 },  /* lower */
  { 0x1f3f, 0x1f37 },  /* lower */
  { 0x1f38, 0x1f30 },  /* upper */
  { 0x1f39, 0x1f31 },  /* upper */
  { 0x1f3a, 0x1f32 },  /* upper */
  { 0x1f3b, 0x1f33 },  /* upper */
  { 0x1f3c, 0x1f34 },  /* upper */
  { 0x1f3d, 0x1f35 },  /* upper */
  { 0x1f3e, 0x1f36 },  /* upper */
  { 0x1f3f, 0x1f37 },  /* upper */
  { 0x1f48, 0x1f40 },  /* lower */
  { 0x1f49, 0x1f41 },  /* lower */
  { 0x1f4a, 0x1f42 },  /* lower */
  { 0x1f4b, 0x1f43 },  /* lower */
  { 0x1f4c, 0x1f44 },  /* lower */
  { 0x1f4d, 0x1f45 },  /* lower */
  { 0x1f46, 0x1f46 },
  { 0x1f47, 0x1f47 },
  { 0x1f48, 0x1f40 },  /* upper */
  { 0x1f49, 0x1f41 },  /* upper */
  { 0x1f4a, 0x1f42 },  /* upper */
  { 0x1f4b, 0x1f43 },  /* upper */
  { 0x1f4c, 0x1f44 },  /* upper */
  { 0x1f4d, 0x1f45 },  /* upper */
  { 0x1f4e, 0x1f4e },
  { 0x1f4f, 0x1f4f },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1f59, 0x1f51 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1f5b, 0x1f53 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1f5d, 0x1f55 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1f5f, 0x1f57 },  /* lower */
  { 0x1f58, 0x1f58 },
  { 0x1f59, 0x1f51 },  /* upper */
  { 0x1f5a, 0x1f5a },
  { 0x1f5b, 0x1f53 },  /* upper */
  { 0x1f5c, 0x1f5c },
  { 0x1f5d, 0x1f55 },  /* upper */
  { 0x1f5e, 0x1f5e },
  { 0x1f5f, 0x1f57 },  /* upper */
  { 0x1f68, 0x1f60 },  /* lower */
  { 0x1f69, 0x1f61 },  /* lower */
  { 0x1f6a, 0x1f62 },  /* lower */
  { 0x1f6b, 0x1f63 },  /* lower */
  { 0x1f6c, 0x1f64 },  /* lower */
  { 0x1f6d, 0x1f65 },  /* lower */
  { 0x1f6e, 0x1f66 },  /* lower */
  { 0x1f6f, 0x1f67 },  /* lower */
  { 0x1f68, 0x1f60 },  /* upper */
  { 0x1f69, 0x1f61 },  /* upper */
  { 0x1f6a, 0x1f62 },  /* upper */
  { 0x1f6b, 0x1f63 },  /* upper */
  { 0x1f6c, 0x1f64 },  /* upper */
  { 0x1f6d, 0x1f65 },  /* upper */
  { 0x1f6e, 0x1f66 },  /* upper */
  { 0x1f6f, 0x1f67 },  /* upper */
  { 0x1fba, 0x1f70 },  /* lower */
  { 0x1fbb, 0x1f71 },  /* lower */
  { 0x1fc8, 0x1f72 },  /* lower */
  { 0x1fc9, 0x1f73 },  /* lower */
  { 0x1fca, 0x1f74 },  /* lower */
  { 0x1fcb, 0x1f75 },  /* lower */
  { 0x1fda, 0x1f76 },  /* lower */
  { 0x1fdb, 0x1f77 },  /* lower */
  { 0x1ff8, 0x1f78 },  /* lower */
  { 0x1ff9, 0x1f79 },  /* lower */
  { 0x1fea, 0x1f7a },  /* lower */
  { 0x1feb, 0x1f7b },  /* lower */
  { 0x1ffa, 0x1f7c },  /* lower */
  { 0x1ffb, 0x1f7d },  /* lower */
  { 0x1f7e, 0x1f7e },
  { 0x1f7f, 0x1f7f },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fb8, 0x1fb0 },  /* lower */
  { 0x1fb9, 0x1fb1 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fb5, 0x1fb5 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fb8, 0x1fb0 },  /* upper */
  { 0x1fb9, 0x1fb1 },  /* upper */
  { 0x1fba, 0x1f70 },  /* upper */
  { 0x1fbb, 0x1f71 },  /* upper */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fbd, 0x1fbd },
  { 0x399, 0x1fbe },  /* lower */
  { 0x1fbf, 0x1fbf },
  { 0x1fc0, 0x1fc0 },
  { 0x1fc1, 0x1fc1 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fc5, 0x1fc5 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fc8, 0x1f72 },  /* upper */
  { 0x1fc9, 0x1f73 },  /* upper */
  { 0x1fca, 0x1f74 },  /* upper */
  { 0x1fcb, 0x1f75 },  /* upper */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fcd, 0x1fcd },
  { 0x1fce, 0x1fce },
  { 0x1fcf, 0x1fcf },
  { 0x1fd8, 0x1fd0 },  /* lower */
  { 0x1fd9, 0x1fd1 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fd4, 0x1fd4 },
  { 0x1fd5, 0x1fd5 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fd8, 0x1fd0 },  /* upper */
  { 0x1fd9, 0x1fd1 },  /* upper */
  { 0x1fda, 0x1f76 },  /* upper */
  { 0x1fdb, 0x1f77 },  /* upper */
  { 0x1fdc, 0x1fdc },
  { 0x1fdd, 0x1fdd },
  { 0x1fde, 0x1fde },
  { 0x1fdf, 0x1fdf },
  { 0x1fe8, 0x1fe0 },  /* lower */
  { 0x1fe9, 0x1fe1 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fec, 0x1fe5 },  /* lower */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1fe8, 0x1fe0 },  /* upper */
  { 0x1fe9, 0x1fe1 },  /* upper */
  { 0x1fea, 0x1f7a },  /* upper */
  { 0x1feb, 0x1f7b },  /* upper */
  { 0x1fec, 0x1fe5 },  /* upper */
  { 0x1fed, 0x1fed },
  { 0x1fee, 0x1fee },
  { 0x1fef, 0x1fef },
  { 0x1ff0, 0x1ff0 },
  { 0x1ff1, 0x1ff1 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1ff5, 0x1ff5 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1ff8, 0x1f78 },  /* upper */
  { 0x1ff9, 0x1f79 },  /* upper */
  { 0x1ffa, 0x1f7c },  /* upper */
  { 0x1ffb, 0x1f7d },  /* upper */
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0x1ffd, 0x1ffd },
  { 0x1ffe, 0x1ffe },
  { 0x1fff, 0x1fff },
};

case_block_t unigen_case_block_0x21[256] = {
  { 0x2100, 0x2100 },
  { 0x2101, 0x2101 },
  { 0x2102, 0x2102 },
  { 0x2103, 0x2103 },
  { 0x2104, 0x2104 },
  { 0x2105, 0x2105 },
  { 0x2106, 0x2106 },
  { 0x2107, 0x2107 },
  { 0x2108, 0x2108 },
  { 0x2109, 0x2109 },
  { 0x210a, 0x210a },
  { 0x210b, 0x210b },
  { 0x210c, 0x210c },
  { 0x210d, 0x210d },
  { 0x210e, 0x210e },
  { 0x210f, 0x210f },
  { 0x2110, 0x2110 },
  { 0x2111, 0x2111 },
  { 0x2112, 0x2112 },
  { 0x2113, 0x2113 },
  { 0x2114, 0x2114 },
  { 0x2115, 0x2115 },
  { 0x2116, 0x2116 },
  { 0x2117, 0x2117 },
  { 0x2118, 0x2118 },
  { 0x2119, 0x2119 },
  { 0x211a, 0x211a },
  { 0x211b, 0x211b },
  { 0x211c, 0x211c },
  { 0x211d, 0x211d },
  { 0x211e, 0x211e },
  { 0x211f, 0x211f },
  { 0x2120, 0x2120 },
  { 0x2121, 0x2121 },
  { 0x2122, 0x2122 },
  { 0x2123, 0x2123 },
  { 0x2124, 0x2124 },
  { 0x2125, 0x2125 },
  { 0x2126, 0x3c9 },  /* upper */
  { 0x2127, 0x2127 },
  { 0x2128, 0x2128 },
  { 0x2129, 0x2129 },
  { 0x212a, 0x6b },  /* upper */
  { 0x212b, 0xe5 },  /* upper */
  { 0x212c, 0x212c },
  { 0x212d, 0x212d },
  { 0x212e, 0x212e },
  { 0x212f, 0x212f },
  { 0x2130, 0x2130 },
  { 0x2131, 0x2131 },
  { 0x2132, 0x2132 },
  { 0x2133, 0x2133 },
  { 0x2134, 0x2134 },
  { 0x2135, 0x2135 },
  { 0x2136, 0x2136 },
  { 0x2137, 0x2137 },
  { 0x2138, 0x2138 },
  { 0x2139, 0x2139 },
  { 0x213a, 0x213a },
  { 0x213b, 0x213b },
  { 0x213c, 0x213c },
  { 0x213d, 0x213d },
  { 0x213e, 0x213e },
  { 0x213f, 0x213f },
  { 0x2140, 0x2140 },
  { 0x2141, 0x2141 },
  { 0x2142, 0x2142 },
  { 0x2143, 0x2143 },
  { 0x2144, 0x2144 },
  { 0x2145, 0x2145 },
  { 0x2146, 0x2146 },
  { 0x2147, 0x2147 },
  { 0x2148, 0x2148 },
  { 0x2149, 0x2149 },
  { 0x214a, 0x214a },
  { 0x214b, 0x214b },
  { 0x214c, 0x214c },
  { 0x214d, 0x214d },
  { 0x214e, 0x214e },
  { 0x214f, 0x214f },
  { 0x2150, 0x2150 },
  { 0x2151, 0x2151 },
  { 0x2152, 0x2152 },
  { 0x2153, 0x2153 },
  { 0x2154, 0x2154 },
  { 0x2155, 0x2155 },
  { 0x2156, 0x2156 },
  { 0x2157, 0x2157 },
  { 0x2158, 0x2158 },
  { 0x2159, 0x2159 },
  { 0x215a, 0x215a },
  { 0x215b, 0x215b },
  { 0x215c, 0x215c },
  { 0x215d, 0x215d },
  { 0x215e, 0x215e },
  { 0x215f, 0x215f },
  { 0x2160, 0x2170 },  /* upper */
  { 0x2161, 0x2171 },  /* upper */
  { 0x2162, 0x2172 },  /* upper */
  { 0x2163, 0x2173 },  /* upper */
  { 0x2164, 0x2174 },  /* upper */
  { 0x2165, 0x2175 },  /* upper */
  { 0x2166, 0x2176 },  /* upper */
  { 0x2167, 0x2177 },  /* upper */
  { 0x2168, 0x2178 },  /* upper */
  { 0x2169, 0x2179 },  /* upper */
  { 0x216a, 0x217a },  /* upper */
  { 0x216b, 0x217b },  /* upper */
  { 0x216c, 0x217c },  /* upper */
  { 0x216d, 0x217d },  /* upper */
  { 0x216e, 0x217e },  /* upper */
  { 0x216f, 0x217f },  /* upper */
  { 0x2160, 0x2170 },  /* lower */
  { 0x2161, 0x2171 },  /* lower */
  { 0x2162, 0x2172 },  /* lower */
  { 0x2163, 0x2173 },  /* lower */
  { 0x2164, 0x2174 },  /* lower */
  { 0x2165, 0x2175 },  /* lower */
  { 0x2166, 0x2176 },  /* lower */
  { 0x2167, 0x2177 },  /* lower */
  { 0x2168, 0x2178 },  /* lower */
  { 0x2169, 0x2179 },  /* lower */
  { 0x216a, 0x217a },  /* lower */
  { 0x216b, 0x217b },  /* lower */
  { 0x216c, 0x217c },  /* lower */
  { 0x216d, 0x217d },  /* lower */
  { 0x216e, 0x217e },  /* lower */
  { 0x216f, 0x217f },  /* lower */
  { 0x2180, 0x2180 },
  { 0x2181, 0x2181 },
  { 0x2182, 0x2182 },
  { 0x2183, 0x2183 },
  { 0x2184, 0x2184 },
  { 0x2185, 0x2185 },
  { 0x2186, 0x2186 },
  { 0x2187, 0x2187 },
  { 0x2188, 0x2188 },
  { 0x2189, 0x2189 },
  { 0x218a, 0x218a },
  { 0x218b, 0x218b },
  { 0x218c, 0x218c },
  { 0x218d, 0x218d },
  { 0x218e, 0x218e },
  { 0x218f, 0x218f },
  { 0x2190, 0x2190 },
  { 0x2191, 0x2191 },
  { 0x2192, 0x2192 },
  { 0x2193, 0x2193 },
  { 0x2194, 0x2194 },
  { 0x2195, 0x2195 },
  { 0x2196, 0x2196 },
  { 0x2197, 0x2197 },
  { 0x2198, 0x2198 },
  { 0x2199, 0x2199 },
  { 0x219a, 0x219a },
  { 0x219b, 0x219b },
  { 0x219c, 0x219c },
  { 0x219d, 0x219d },
  { 0x219e, 0x219e },
  { 0x219f, 0x219f },
  { 0x21a0, 0x21a0 },
  { 0x21a1, 0x21a1 },
  { 0x21a2, 0x21a2 },
  { 0x21a3, 0x21a3 },
  { 0x21a4, 0x21a4 },
  { 0x21a5, 0x21a5 },
  { 0x21a6, 0x21a6 },
  { 0x21a7, 0x21a7 },
  { 0x21a8, 0x21a8 },
  { 0x21a9, 0x21a9 },
  { 0x21aa, 0x21aa },
  { 0x21ab, 0x21ab },
  { 0x21ac, 0x21ac },
  { 0x21ad, 0x21ad },
  { 0x21ae, 0x21ae },
  { 0x21af, 0x21af },
  { 0x21b0, 0x21b0 },
  { 0x21b1, 0x21b1 },
  { 0x21b2, 0x21b2 },
  { 0x21b3, 0x21b3 },
  { 0x21b4, 0x21b4 },
  { 0x21b5, 0x21b5 },
  { 0x21b6, 0x21b6 },
  { 0x21b7, 0x21b7 },
  { 0x21b8, 0x21b8 },
  { 0x21b9, 0x21b9 },
  { 0x21ba, 0x21ba },
  { 0x21bb, 0x21bb },
  { 0x21bc, 0x21bc },
  { 0x21bd, 0x21bd },
  { 0x21be, 0x21be },
  { 0x21bf, 0x21bf },
  { 0x21c0, 0x21c0 },
  { 0x21c1, 0x21c1 },
  { 0x21c2, 0x21c2 },
  { 0x21c3, 0x21c3 },
  { 0x21c4, 0x21c4 },
  { 0x21c5, 0x21c5 },
  { 0x21c6, 0x21c6 },
  { 0x21c7, 0x21c7 },
  { 0x21c8, 0x21c8 },
  { 0x21c9, 0x21c9 },
  { 0x21ca, 0x21ca },
  { 0x21cb, 0x21cb },
  { 0x21cc, 0x21cc },
  { 0x21cd, 0x21cd },
  { 0x21ce, 0x21ce },
  { 0x21cf, 0x21cf },
  { 0x21d0, 0x21d0 },
  { 0x21d1, 0x21d1 },
  { 0x21d2, 0x21d2 },
  { 0x21d3, 0x21d3 },
  { 0x21d4, 0x21d4 },
  { 0x21d5, 0x21d5 },
  { 0x21d6, 0x21d6 },
  { 0x21d7, 0x21d7 },
  { 0x21d8, 0x21d8 },
  { 0x21d9, 0x21d9 },
  { 0x21da, 0x21da },
  { 0x21db, 0x21db },
  { 0x21dc, 0x21dc },
  { 0x21dd, 0x21dd },
  { 0x21de, 0x21de },
  { 0x21df, 0x21df },
  { 0x21e0, 0x21e0 },
  { 0x21e1, 0x21e1 },
  { 0x21e2, 0x21e2 },
  { 0x21e3, 0x21e3 },
  { 0x21e4, 0x21e4 },
  { 0x21e5, 0x21e5 },
  { 0x21e6, 0x21e6 },
  { 0x21e7, 0x21e7 },
  { 0x21e8, 0x21e8 },
  { 0x21e9, 0x21e9 },
  { 0x21ea, 0x21ea },
  { 0x21eb, 0x21eb },
  { 0x21ec, 0x21ec },
  { 0x21ed, 0x21ed },
  { 0x21ee, 0x21ee },
  { 0x21ef, 0x21ef },
  { 0x21f0, 0x21f0 },
  { 0x21f1, 0x21f1 },
  { 0x21f2, 0x21f2 },
  { 0x21f3, 0x21f3 },
  { 0x21f4, 0x21f4 },
  { 0x21f5, 0x21f5 },
  { 0x21f6, 0x21f6 },
  { 0x21f7, 0x21f7 },
  { 0x21f8, 0x21f8 },
  { 0x21f9, 0x21f9 },
  { 0x21fa, 0x21fa },
  { 0x21fb, 0x21fb },
  { 0x21fc, 0x21fc },
  { 0x21fd, 0x21fd },
  { 0x21fe, 0x21fe },
  { 0x21ff, 0x21ff },
};

case_block_t unigen_case_block_0x24[256] = {
  { 0x2400, 0x2400 },
  { 0x2401, 0x2401 },
  { 0x2402, 0x2402 },
  { 0x2403, 0x2403 },
  { 0x2404, 0x2404 },
  { 0x2405, 0x2405 },
  { 0x2406, 0x2406 },
  { 0x2407, 0x2407 },
  { 0x2408, 0x2408 },
  { 0x2409, 0x2409 },
  { 0x240a, 0x240a },
  { 0x240b, 0x240b },
  { 0x240c, 0x240c },
  { 0x240d, 0x240d },
  { 0x240e, 0x240e },
  { 0x240f, 0x240f },
  { 0x2410, 0x2410 },
  { 0x2411, 0x2411 },
  { 0x2412, 0x2412 },
  { 0x2413, 0x2413 },
  { 0x2414, 0x2414 },
  { 0x2415, 0x2415 },
  { 0x2416, 0x2416 },
  { 0x2417, 0x2417 },
  { 0x2418, 0x2418 },
  { 0x2419, 0x2419 },
  { 0x241a, 0x241a },
  { 0x241b, 0x241b },
  { 0x241c, 0x241c },
  { 0x241d, 0x241d },
  { 0x241e, 0x241e },
  { 0x241f, 0x241f },
  { 0x2420, 0x2420 },
  { 0x2421, 0x2421 },
  { 0x2422, 0x2422 },
  { 0x2423, 0x2423 },
  { 0x2424, 0x2424 },
  { 0x2425, 0x2425 },
  { 0x2426, 0x2426 },
  { 0x2427, 0x2427 },
  { 0x2428, 0x2428 },
  { 0x2429, 0x2429 },
  { 0x242a, 0x242a },
  { 0x242b, 0x242b },
  { 0x242c, 0x242c },
  { 0x242d, 0x242d },
  { 0x242e, 0x242e },
  { 0x242f, 0x242f },
  { 0x2430, 0x2430 },
  { 0x2431, 0x2431 },
  { 0x2432, 0x2432 },
  { 0x2433, 0x2433 },
  { 0x2434, 0x2434 },
  { 0x2435, 0x2435 },
  { 0x2436, 0x2436 },
  { 0x2437, 0x2437 },
  { 0x2438, 0x2438 },
  { 0x2439, 0x2439 },
  { 0x243a, 0x243a },
  { 0x243b, 0x243b },
  { 0x243c, 0x243c },
  { 0x243d, 0x243d },
  { 0x243e, 0x243e },
  { 0x243f, 0x243f },
  { 0x2440, 0x2440 },
  { 0x2441, 0x2441 },
  { 0x2442, 0x2442 },
  { 0x2443, 0x2443 },
  { 0x2444, 0x2444 },
  { 0x2445, 0x2445 },
  { 0x2446, 0x2446 },
  { 0x2447, 0x2447 },
  { 0x2448, 0x2448 },
  { 0x2449, 0x2449 },
  { 0x244a, 0x244a },
  { 0x244b, 0x244b },
  { 0x244c, 0x244c },
  { 0x244d, 0x244d },
  { 0x244e, 0x244e },
  { 0x244f, 0x244f },
  { 0x2450, 0x2450 },
  { 0x2451, 0x2451 },
  { 0x2452, 0x2452 },
  { 0x2453, 0x2453 },
  { 0x2454, 0x2454 },
  { 0x2455, 0x2455 },
  { 0x2456, 0x2456 },
  { 0x2457, 0x2457 },
  { 0x2458, 0x2458 },
  { 0x2459, 0x2459 },
  { 0x245a, 0x245a },
  { 0x245b, 0x245b },
  { 0x245c, 0x245c },
  { 0x245d, 0x245d },
  { 0x245e, 0x245e },
  { 0x245f, 0x245f },
  { 0x2460, 0x2460 },
  { 0x2461, 0x2461 },
  { 0x2462, 0x2462 },
  { 0x2463, 0x2463 },
  { 0x2464, 0x2464 },
  { 0x2465, 0x2465 },
  { 0x2466, 0x2466 },
  { 0x2467, 0x2467 },
  { 0x2468, 0x2468 },
  { 0x2469, 0x2469 },
  { 0x246a, 0x246a },
  { 0x246b, 0x246b },
  { 0x246c, 0x246c },
  { 0x246d, 0x246d },
  { 0x246e, 0x246e },
  { 0x246f, 0x246f },
  { 0x2470, 0x2470 },
  { 0x2471, 0x2471 },
  { 0x2472, 0x2472 },
  { 0x2473, 0x2473 },
  { 0x2474, 0x2474 },
  { 0x2475, 0x2475 },
  { 0x2476, 0x2476 },
  { 0x2477, 0x2477 },
  { 0x2478, 0x2478 },
  { 0x2479, 0x2479 },
  { 0x247a, 0x247a },
  { 0x247b, 0x247b },
  { 0x247c, 0x247c },
  { 0x247d, 0x247d },
  { 0x247e, 0x247e },
  { 0x247f, 0x247f },
  { 0x2480, 0x2480 },
  { 0x2481, 0x2481 },
  { 0x2482, 0x2482 },
  { 0x2483, 0x2483 },
  { 0x2484, 0x2484 },
  { 0x2485, 0x2485 },
  { 0x2486, 0x2486 },
  { 0x2487, 0x2487 },
  { 0x2488, 0x2488 },
  { 0x2489, 0x2489 },
  { 0x248a, 0x248a },
  { 0x248b, 0x248b },
  { 0x248c, 0x248c },
  { 0x248d, 0x248d },
  { 0x248e, 0x248e },
  { 0x248f, 0x248f },
  { 0x2490, 0x2490 },
  { 0x2491, 0x2491 },
  { 0x2492, 0x2492 },
  { 0x2493, 0x2493 },
  { 0x2494, 0x2494 },
  { 0x2495, 0x2495 },
  { 0x2496, 0x2496 },
  { 0x2497, 0x2497 },
  { 0x2498, 0x2498 },
  { 0x2499, 0x2499 },
  { 0x249a, 0x249a },
  { 0x249b, 0x249b },
  { 0x249c, 0x249c },
  { 0x249d, 0x249d },
  { 0x249e, 0x249e },
  { 0x249f, 0x249f },
  { 0x24a0, 0x24a0 },
  { 0x24a1, 0x24a1 },
  { 0x24a2, 0x24a2 },
  { 0x24a3, 0x24a3 },
  { 0x24a4, 0x24a4 },
  { 0x24a5, 0x24a5 },
  { 0x24a6, 0x24a6 },
  { 0x24a7, 0x24a7 },
  { 0x24a8, 0x24a8 },
  { 0x24a9, 0x24a9 },
  { 0x24aa, 0x24aa },
  { 0x24ab, 0x24ab },
  { 0x24ac, 0x24ac },
  { 0x24ad, 0x24ad },
  { 0x24ae, 0x24ae },
  { 0x24af, 0x24af },
  { 0x24b0, 0x24b0 },
  { 0x24b1, 0x24b1 },
  { 0x24b2, 0x24b2 },
  { 0x24b3, 0x24b3 },
  { 0x24b4, 0x24b4 },
  { 0x24b5, 0x24b5 },
  { 0x24b6, 0x24d0 },  /* upper */
  { 0x24b7, 0x24d1 },  /* upper */
  { 0x24b8, 0x24d2 },  /* upper */
  { 0x24b9, 0x24d3 },  /* upper */
  { 0x24ba, 0x24d4 },  /* upper */
  { 0x24bb, 0x24d5 },  /* upper */
  { 0x24bc, 0x24d6 },  /* upper */
  { 0x24bd, 0x24d7 },  /* upper */
  { 0x24be, 0x24d8 },  /* upper */
  { 0x24bf, 0x24d9 },  /* upper */
  { 0x24c0, 0x24da },  /* upper */
  { 0x24c1, 0x24db },  /* upper */
  { 0x24c2, 0x24dc },  /* upper */
  { 0x24c3, 0x24dd },  /* upper */
  { 0x24c4, 0x24de },  /* upper */
  { 0x24c5, 0x24df },  /* upper */
  { 0x24c6, 0x24e0 },  /* upper */
  { 0x24c7, 0x24e1 },  /* upper */
  { 0x24c8, 0x24e2 },  /* upper */
  { 0x24c9, 0x24e3 },  /* upper */
  { 0x24ca, 0x24e4 },  /* upper */
  { 0x24cb, 0x24e5 },  /* upper */
  { 0x24cc, 0x24e6 },  /* upper */
  { 0x24cd, 0x24e7 },  /* upper */
  { 0x24ce, 0x24e8 },  /* upper */
  { 0x24cf, 0x24e9 },  /* upper */
  { 0x24b6, 0x24d0 },  /* lower */
  { 0x24b7, 0x24d1 },  /* lower */
  { 0x24b8, 0x24d2 },  /* lower */
  { 0x24b9, 0x24d3 },  /* lower */
  { 0x24ba, 0x24d4 },  /* lower */
  { 0x24bb, 0x24d5 },  /* lower */
  { 0x24bc, 0x24d6 },  /* lower */
  { 0x24bd, 0x24d7 },  /* lower */
  { 0x24be, 0x24d8 },  /* lower */
  { 0x24bf, 0x24d9 },  /* lower */
  { 0x24c0, 0x24da },  /* lower */
  { 0x24c1, 0x24db },  /* lower */
  { 0x24c2, 0x24dc },  /* lower */
  { 0x24c3, 0x24dd },  /* lower */
  { 0x24c4, 0x24de },  /* lower */
  { 0x24c5, 0x24df },  /* lower */
  { 0x24c6, 0x24e0 },  /* lower */
  { 0x24c7, 0x24e1 },  /* lower */
  { 0x24c8, 0x24e2 },  /* lower */
  { 0x24c9, 0x24e3 },  /* lower */
  { 0x24ca, 0x24e4 },  /* lower */
  { 0x24cb, 0x24e5 },  /* lower */
  { 0x24cc, 0x24e6 },  /* lower */
  { 0x24cd, 0x24e7 },  /* lower */
  { 0x24ce, 0x24e8 },  /* lower */
  { 0x24cf, 0x24e9 },  /* lower */
  { 0x24ea, 0x24ea },
  { 0x24eb, 0x24eb },
  { 0x24ec, 0x24ec },
  { 0x24ed, 0x24ed },
  { 0x24ee, 0x24ee },
  { 0x24ef, 0x24ef },
  { 0x24f0, 0x24f0 },
  { 0x24f1, 0x24f1 },
  { 0x24f2, 0x24f2 },
  { 0x24f3, 0x24f3 },
  { 0x24f4, 0x24f4 },
  { 0x24f5, 0x24f5 },
  { 0x24f6, 0x24f6 },
  { 0x24f7, 0x24f7 },
  { 0x24f8, 0x24f8 },
  { 0x24f9, 0x24f9 },
  { 0x24fa, 0x24fa },
  { 0x24fb, 0x24fb },
  { 0x24fc, 0x24fc },
  { 0x24fd, 0x24fd },
  { 0x24fe, 0x24fe },
  { 0x24ff, 0x24ff },
};

case_block_t unigen_case_block_0xfb[256] = {
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xfb07, 0xfb07 },
  { 0xfb08, 0xfb08 },
  { 0xfb09, 0xfb09 },
  { 0xfb0a, 0xfb0a },
  { 0xfb0b, 0xfb0b },
  { 0xfb0c, 0xfb0c },
  { 0xfb0d, 0xfb0d },
  { 0xfb0e, 0xfb0e },
  { 0xfb0f, 0xfb0f },
  { 0xfb10, 0xfb10 },
  { 0xfb11, 0xfb11 },
  { 0xfb12, 0xfb12 },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xFFFFFFFF, 0xFFFFFFFF },
  { 0xfb18, 0xfb18 },
  { 0xfb19, 0xfb19 },
  { 0xfb1a, 0xfb1a },
  { 0xfb1b, 0xfb1b },
  { 0xfb1c, 0xfb1c },
  { 0xfb1d, 0xfb1d },
  { 0xfb1e, 0xfb1e },
  { 0xfb1f, 0xfb1f },
  { 0xfb20, 0xfb20 },
  { 0xfb21, 0xfb21 },
  { 0xfb22, 0xfb22 },
  { 0xfb23, 0xfb23 },
  { 0xfb24, 0xfb24 },
  { 0xfb25, 0xfb25 },
  { 0xfb26, 0xfb26 },
  { 0xfb27, 0xfb27 },
  { 0xfb28, 0xfb28 },
  { 0xfb29, 0xfb29 },
  { 0xfb2a, 0xfb2a },
  { 0xfb2b, 0xfb2b },
  { 0xfb2c, 0xfb2c },
  { 0xfb2d, 0xfb2d },
  { 0xfb2e, 0xfb2e },
  { 0xfb2f, 0xfb2f },
  { 0xfb30, 0xfb30 },
  { 0xfb31, 0xfb31 },
  { 0xfb32, 0xfb32 },
  { 0xfb33, 0xfb33 },
  { 0xfb34, 0xfb34 },
  { 0xfb35, 0xfb35 },
  { 0xfb36, 0xfb36 },
  { 0xfb37, 0xfb37 },
  { 0xfb38, 0xfb38 },
  { 0xfb39, 0xfb39 },
  { 0xfb3a, 0xfb3a },
  { 0xfb3b, 0xfb3b },
  { 0xfb3c, 0xfb3c },
  { 0xfb3d, 0xfb3d },
  { 0xfb3e, 0xfb3e },
  { 0xfb3f, 0xfb3f },
  { 0xfb40, 0xfb40 },
  { 0xfb41, 0xfb41 },
  { 0xfb42, 0xfb42 },
  { 0xfb43, 0xfb43 },
  { 0xfb44, 0xfb44 },
  { 0xfb45, 0xfb45 },
  { 0xfb46, 0xfb46 },
  { 0xfb47, 0xfb47 },
  { 0xfb48, 0xfb48 },
  { 0xfb49, 0xfb49 },
  { 0xfb4a, 0xfb4a },
  { 0xfb4b, 0xfb4b },
  { 0xfb4c, 0xfb4c },
  { 0xfb4d, 0xfb4d },
  { 0xfb4e, 0xfb4e },
  { 0xfb4f, 0xfb4f },
  { 0xfb50, 0xfb50 },
  { 0xfb51, 0xfb51 },
  { 0xfb52, 0xfb52 },
  { 0xfb53, 0xfb53 },
  { 0xfb54, 0xfb54 },
  { 0xfb55, 0xfb55 },
  { 0xfb56, 0xfb56 },
  { 0xfb57, 0xfb57 },
  { 0xfb58, 0xfb58 },
  { 0xfb59, 0xfb59 },
  { 0xfb5a, 0xfb5a },
  { 0xfb5b, 0xfb5b },
  { 0xfb5c, 0xfb5c },
  { 0xfb5d, 0xfb5d },
  { 0xfb5e, 0xfb5e },
  { 0xfb5f, 0xfb5f },
  { 0xfb60, 0xfb60 },
  { 0xfb61, 0xfb61 },
  { 0xfb62, 0xfb62 },
  { 0xfb63, 0xfb63 },
  { 0xfb64, 0xfb64 },
  { 0xfb65, 0xfb65 },
  { 0xfb66, 0xfb66 },
  { 0xfb67, 0xfb67 },
  { 0xfb68, 0xfb68 },
  { 0xfb69, 0xfb69 },
  { 0xfb6a, 0xfb6a },
  { 0xfb6b, 0xfb6b },
  { 0xfb6c, 0xfb6c },
  { 0xfb6d, 0xfb6d },
  { 0xfb6e, 0xfb6e },
  { 0xfb6f, 0xfb6f },
  { 0xfb70, 0xfb70 },
  { 0xfb71, 0xfb71 },
  { 0xfb72, 0xfb72 },
  { 0xfb73, 0xfb73 },
  { 0xfb74, 0xfb74 },
  { 0xfb75, 0xfb75 },
  { 0xfb76, 0xfb76 },
  { 0xfb77, 0xfb77 },
  { 0xfb78, 0xfb78 },
  { 0xfb79, 0xfb79 },
  { 0xfb7a, 0xfb7a },
  { 0xfb7b, 0xfb7b },
  { 0xfb7c, 0xfb7c },
  { 0xfb7d, 0xfb7d },
  { 0xfb7e, 0xfb7e },
  { 0xfb7f, 0xfb7f },
  { 0xfb80, 0xfb80 },
  { 0xfb81, 0xfb81 },
  { 0xfb82, 0xfb82 },
  { 0xfb83, 0xfb83 },
  { 0xfb84, 0xfb84 },
  { 0xfb85, 0xfb85 },
  { 0xfb86, 0xfb86 },
  { 0xfb87, 0xfb87 },
  { 0xfb88, 0xfb88 },
  { 0xfb89, 0xfb89 },
  { 0xfb8a, 0xfb8a },
  { 0xfb8b, 0xfb8b },
  { 0xfb8c, 0xfb8c },
  { 0xfb8d, 0xfb8d },
  { 0xfb8e, 0xfb8e },
  { 0xfb8f, 0xfb8f },
  { 0xfb90, 0xfb90 },
  { 0xfb91, 0xfb91 },
  { 0xfb92, 0xfb92 },
  { 0xfb93, 0xfb93 },
  { 0xfb94, 0xfb94 },
  { 0xfb95, 0xfb95 },
  { 0xfb96, 0xfb96 },
  { 0xfb97, 0xfb97 },
  { 0xfb98, 0xfb98 },
  { 0xfb99, 0xfb99 },
  { 0xfb9a, 0xfb9a },
  { 0xfb9b, 0xfb9b },
  { 0xfb9c, 0xfb9c },
  { 0xfb9d, 0xfb9d },
  { 0xfb9e, 0xfb9e },
  { 0xfb9f, 0xfb9f },
  { 0xfba0, 0xfba0 },
  { 0xfba1, 0xfba1 },
  { 0xfba2, 0xfba2 },
  { 0xfba3, 0xfba3 },
  { 0xfba4, 0xfba4 },
  { 0xfba5, 0xfba5 },
  { 0xfba6, 0xfba6 },
  { 0xfba7, 0xfba7 },
  { 0xfba8, 0xfba8 },
  { 0xfba9, 0xfba9 },
  { 0xfbaa, 0xfbaa },
  { 0xfbab, 0xfbab },
  { 0xfbac, 0xfbac },
  { 0xfbad, 0xfbad },
  { 0xfbae, 0xfbae },
  { 0xfbaf, 0xfbaf },
  { 0xfbb0, 0xfbb0 },
  { 0xfbb1, 0xfbb1 },
  { 0xfbb2, 0xfbb2 },
  { 0xfbb3, 0xfbb3 },
  { 0xfbb4, 0xfbb4 },
  { 0xfbb5, 0xfbb5 },
  { 0xfbb6, 0xfbb6 },
  { 0xfbb7, 0xfbb7 },
  { 0xfbb8, 0xfbb8 },
  { 0xfbb9, 0xfbb9 },
  { 0xfbba, 0xfbba },
  { 0xfbbb, 0xfbbb },
  { 0xfbbc, 0xfbbc },
  { 0xfbbd, 0xfbbd },
  { 0xfbbe, 0xfbbe },
  { 0xfbbf, 0xfbbf },
  { 0xfbc0, 0xfbc0 },
  { 0xfbc1, 0xfbc1 },
  { 0xfbc2, 0xfbc2 },
  { 0xfbc3, 0xfbc3 },
  { 0xfbc4, 0xfbc4 },
  { 0xfbc5, 0xfbc5 },
  { 0xfbc6, 0xfbc6 },
  { 0xfbc7, 0xfbc7 },
  { 0xfbc8, 0xfbc8 },
  { 0xfbc9, 0xfbc9 },
  { 0xfbca, 0xfbca },
  { 0xfbcb, 0xfbcb },
  { 0xfbcc, 0xfbcc },
  { 0xfbcd, 0xfbcd },
  { 0xfbce, 0xfbce },
  { 0xfbcf, 0xfbcf },
  { 0xfbd0, 0xfbd0 },
  { 0xfbd1, 0xfbd1 },
  { 0xfbd2, 0xfbd2 },
  { 0xfbd3, 0xfbd3 },
  { 0xfbd4, 0xfbd4 },
  { 0xfbd5, 0xfbd5 },
  { 0xfbd6, 0xfbd6 },
  { 0xfbd7, 0xfbd7 },
  { 0xfbd8, 0xfbd8 },
  { 0xfbd9, 0xfbd9 },
  { 0xfbda, 0xfbda },
  { 0xfbdb, 0xfbdb },
  { 0xfbdc, 0xfbdc },
  { 0xfbdd, 0xfbdd },
  { 0xfbde, 0xfbde },
  { 0xfbdf, 0xfbdf },
  { 0xfbe0, 0xfbe0 },
  { 0xfbe1, 0xfbe1 },
  { 0xfbe2, 0xfbe2 },
  { 0xfbe3, 0xfbe3 },
  { 0xfbe4, 0xfbe4 },
  { 0xfbe5, 0xfbe5 },
  { 0xfbe6, 0xfbe6 },
  { 0xfbe7, 0xfbe7 },
  { 0xfbe8, 0xfbe8 },
  { 0xfbe9, 0xfbe9 },
  { 0xfbea, 0xfbea },
  { 0xfbeb, 0xfbeb },
  { 0xfbec, 0xfbec },
  { 0xfbed, 0xfbed },
  { 0xfbee, 0xfbee },
  { 0xfbef, 0xfbef },
  { 0xfbf0, 0xfbf0 },
  { 0xfbf1, 0xfbf1 },
  { 0xfbf2, 0xfbf2 },
  { 0xfbf3, 0xfbf3 },
  { 0xfbf4, 0xfbf4 },
  { 0xfbf5, 0xfbf5 },
  { 0xfbf6, 0xfbf6 },
  { 0xfbf7, 0xfbf7 },
  { 0xfbf8, 0xfbf8 },
  { 0xfbf9, 0xfbf9 },
  { 0xfbfa, 0xfbfa },
  { 0xfbfb, 0xfbfb },
  { 0xfbfc, 0xfbfc },
  { 0xfbfd, 0xfbfd },
  { 0xfbfe, 0xfbfe },
  { 0xfbff, 0xfbff },
};

case_block_t unigen_case_block_0xff[256] = {
  { 0xff00, 0xff00 },
  { 0xff01, 0xff01 },
  { 0xff02, 0xff02 },
  { 0xff03, 0xff03 },
  { 0xff04, 0xff04 },
  { 0xff05, 0xff05 },
  { 0xff06, 0xff06 },
  { 0xff07, 0xff07 },
  { 0xff08, 0xff08 },
  { 0xff09, 0xff09 },
  { 0xff0a, 0xff0a },
  { 0xff0b, 0xff0b },
  { 0xff0c, 0xff0c },
  { 0xff0d, 0xff0d },
  { 0xff0e, 0xff0e },
  { 0xff0f, 0xff0f },
  { 0xff10, 0xff10 },
  { 0xff11, 0xff11 },
  { 0xff12, 0xff12 },
  { 0xff13, 0xff13 },
  { 0xff14, 0xff14 },
  { 0xff15, 0xff15 },
  { 0xff16, 0xff16 },
  { 0xff17, 0xff17 },
  { 0xff18, 0xff18 },
  { 0xff19, 0xff19 },
  { 0xff1a, 0xff1a },
  { 0xff1b, 0xff1b },
  { 0xff1c, 0xff1c },
  { 0xff1d, 0xff1d },
  { 0xff1e, 0xff1e },
  { 0xff1f, 0xff1f },
  { 0xff20, 0xff20 },
  { 0xff21, 0xff41 },  /* upper */
  { 0xff22, 0xff42 },  /* upper */
  { 0xff23, 0xff43 },  /* upper */
  { 0xff24, 0xff44 },  /* upper */
  { 0xff25, 0xff45 },  /* upper */
  { 0xff26, 0xff46 },  /* upper */
  { 0xff27, 0xff47 },  /* upper */
  { 0xff28, 0xff48 },  /* upper */
  { 0xff29, 0xff49 },  /* upper */
  { 0xff2a, 0xff4a },  /* upper */
  { 0xff2b, 0xff4b },  /* upper */
  { 0xff2c, 0xff4c },  /* upper */
  { 0xff2d, 0xff4d },  /* upper */
  { 0xff2e, 0xff4e },  /* upper */
  { 0xff2f, 0xff4f },  /* upper */
  { 0xff30, 0xff50 },  /* upper */
  { 0xff31, 0xff51 },  /* upper */
  { 0xff32, 0xff52 },  /* upper */
  { 0xff33, 0xff53 },  /* upper */
  { 0xff34, 0xff54 },  /* upper */
  { 0xff35, 0xff55 },  /* upper */
  { 0xff36, 0xff56 },  /* upper */
  { 0xff37, 0xff57 },  /* upper */
  { 0xff38, 0xff58 },  /* upper */
  { 0xff39, 0xff59 },  /* upper */
  { 0xff3a, 0xff5a },  /* upper */
  { 0xff3b, 0xff3b },
  { 0xff3c, 0xff3c },
  { 0xff3d, 0xff3d },
  { 0xff3e, 0xff3e },
  { 0xff3f, 0xff3f },
  { 0xff40, 0xff40 },
  { 0xff21, 0xff41 },  /* lower */
  { 0xff22, 0xff42 },  /* lower */
  { 0xff23, 0xff43 },  /* lower */
  { 0xff24, 0xff44 },  /* lower */
  { 0xff25, 0xff45 },  /* lower */
  { 0xff26, 0xff46 },  /* lower */
  { 0xff27, 0xff47 },  /* lower */
  { 0xff28, 0xff48 },  /* lower */
  { 0xff29, 0xff49 },  /* lower */
  { 0xff2a, 0xff4a },  /* lower */
  { 0xff2b, 0xff4b },  /* lower */
  { 0xff2c, 0xff4c },  /* lower */
  { 0xff2d, 0xff4d },  /* lower */
  { 0xff2e, 0xff4e },  /* lower */
  { 0xff2f, 0xff4f },  /* lower */
  { 0xff30, 0xff50 },  /* lower */
  { 0xff31, 0xff51 },  /* lower */
  { 0xff32, 0xff52 },  /* lower */
  { 0xff33, 0xff53 },  /* lower */
  { 0xff34, 0xff54 },  /* lower */
  { 0xff35, 0xff55 },  /* lower */
  { 0xff36, 0xff56 },  /* lower */
  { 0xff37, 0xff57 },  /* lower */
  { 0xff38, 0xff58 },  /* lower */
  { 0xff39, 0xff59 },  /* lower */
  { 0xff3a, 0xff5a },  /* lower */
  { 0xff5b, 0xff5b },
  { 0xff5c, 0xff5c },
  { 0xff5d, 0xff5d },
  { 0xff5e, 0xff5e },
  { 0xff5f, 0xff5f },
  { 0xff60, 0xff60 },
  { 0xff61, 0xff61 },
  { 0xff62, 0xff62 },
  { 0xff63, 0xff63 },
  { 0xff64, 0xff64 },
  { 0xff65, 0xff65 },
  { 0xff66, 0xff66 },
  { 0xff67, 0xff67 },
  { 0xff68, 0xff68 },
  { 0xff69, 0xff69 },
  { 0xff6a, 0xff6a },
  { 0xff6b, 0xff6b },
  { 0xff6c, 0xff6c },
  { 0xff6d, 0xff6d },
  { 0xff6e, 0xff6e },
  { 0xff6f, 0xff6f },
  { 0xff70, 0xff70 },
  { 0xff71, 0xff71 },
  { 0xff72, 0xff72 },
  { 0xff73, 0xff73 },
  { 0xff74, 0xff74 },
  { 0xff75, 0xff75 },
  { 0xff76, 0xff76 },
  { 0xff77, 0xff77 },
  { 0xff78, 0xff78 },
  { 0xff79, 0xff79 },
  { 0xff7a, 0xff7a },
  { 0xff7b, 0xff7b },
  { 0xff7c, 0xff7c },
  { 0xff7d, 0xff7d },
  { 0xff7e, 0xff7e },
  { 0xff7f, 0xff7f },
  { 0xff80, 0xff80 },
  { 0xff81, 0xff81 },
  { 0xff82, 0xff82 },
  { 0xff83, 0xff83 },
  { 0xff84, 0xff84 },
  { 0xff85, 0xff85 },
  { 0xff86, 0xff86 },
  { 0xff87, 0xff87 },
  { 0xff88, 0xff88 },
  { 0xff89, 0xff89 },
  { 0xff8a, 0xff8a },
  { 0xff8b, 0xff8b },
  { 0xff8c, 0xff8c },
  { 0xff8d, 0xff8d },
  { 0xff8e, 0xff8e },
  { 0xff8f, 0xff8f },
  { 0xff90, 0xff90 },
  { 0xff91, 0xff91 },
  { 0xff92, 0xff92 },
  { 0xff93, 0xff93 },
  { 0xff94, 0xff94 },
  { 0xff95, 0xff95 },
  { 0xff96, 0xff96 },
  { 0xff97, 0xff97 },
  { 0xff98, 0xff98 },
  { 0xff99, 0xff99 },
  { 0xff9a, 0xff9a },
  { 0xff9b, 0xff9b },
  { 0xff9c, 0xff9c },
  { 0xff9d, 0xff9d },
  { 0xff9e, 0xff9e },
  { 0xff9f, 0xff9f },
  { 0xffa0, 0xffa0 },
  { 0xffa1, 0xffa1 },
  { 0xffa2, 0xffa2 },
  { 0xffa3, 0xffa3 },
  { 0xffa4, 0xffa4 },
  { 0xffa5, 0xffa5 },
  { 0xffa6, 0xffa6 },
  { 0xffa7, 0xffa7 },
  { 0xffa8, 0xffa8 },
  { 0xffa9, 0xffa9 },
  { 0xffaa, 0xffaa },
  { 0xffab, 0xffab },
  { 0xffac, 0xffac },
  { 0xffad, 0xffad },
  { 0xffae, 0xffae },
  { 0xffaf, 0xffaf },
  { 0xffb0, 0xffb0 },
  { 0xffb1, 0xffb1 },
  { 0xffb2, 0xffb2 },
  { 0xffb3, 0xffb3 },
  { 0xffb4, 0xffb4 },
  { 0xffb5, 0xffb5 },
  { 0xffb6, 0xffb6 },
  { 0xffb7, 0xffb7 },
  { 0xffb8, 0xffb8 },
  { 0xffb9, 0xffb9 },
  { 0xffba, 0xffba },
  { 0xffbb, 0xffbb },
  { 0xffbc, 0xffbc },
  { 0xffbd, 0xffbd },
  { 0xffbe, 0xffbe },
  { 0xffbf, 0xffbf },
  { 0xffc0, 0xffc0 },
  { 0xffc1, 0xffc1 },
  { 0xffc2, 0xffc2 },
  { 0xffc3, 0xffc3 },
  { 0xffc4, 0xffc4 },
  { 0xffc5, 0xffc5 },
  { 0xffc6, 0xffc6 },
  { 0xffc7, 0xffc7 },
  { 0xffc8, 0xffc8 },
  { 0xffc9, 0xffc9 },
  { 0xffca, 0xffca },
  { 0xffcb, 0xffcb },
  { 0xffcc, 0xffcc },
  { 0xffcd, 0xffcd },
  { 0xffce, 0xffce },
  { 0xffcf, 0xffcf },
  { 0xffd0, 0xffd0 },
  { 0xffd1, 0xffd1 },
  { 0xffd2, 0xffd2 },
  { 0xffd3, 0xffd3 },
  { 0xffd4, 0xffd4 },
  { 0xffd5, 0xffd5 },
  { 0xffd6, 0xffd6 },
  { 0xffd7, 0xffd7 },
  { 0xffd8, 0xffd8 },
  { 0xffd9, 0xffd9 },
  { 0xffda, 0xffda },
  { 0xffdb, 0xffdb },
  { 0xffdc, 0xffdc },
  { 0xffdd, 0xffdd },
  { 0xffde, 0xffde },
  { 0xffdf, 0xffdf },
  { 0xffe0, 0xffe0 },
  { 0xffe1, 0xffe1 },
  { 0xffe2, 0xffe2 },
  { 0xffe3, 0xffe3 },
  { 0xffe4, 0xffe4 },
  { 0xffe5, 0xffe5 },
  { 0xffe6, 0xffe6 },
  { 0xffe7, 0xffe7 },
  { 0xffe8, 0xffe8 },
  { 0xffe9, 0xffe9 },
  { 0xffea, 0xffea },
  { 0xffeb, 0xffeb },
  { 0xffec, 0xffec },
  { 0xffed, 0xffed },
  { 0xffee, 0xffee },
  { 0xffef, 0xffef },
  { 0xfff0, 0xfff0 },
  { 0xfff1, 0xfff1 },
  { 0xfff2, 0xfff2 },
  { 0xfff3, 0xfff3 },
  { 0xfff4, 0xfff4 },
  { 0xfff5, 0xfff5 },
  { 0xfff6, 0xfff6 },
  { 0xfff7, 0xfff7 },
  { 0xfff8, 0xfff8 },
  { 0xfff9, 0xfff9 },
  { 0xfffa, 0xfffa },
  { 0xfffb, 0xfffb },
  { 0xfffc, 0xfffc },
  { 0xfffd, 0xfffd },
  { 0xfffe, 0xfffe },
  { 0xffff, 0xffff },
};

case_block_t unigen_case_block_0x104[256] = {
  { 0x10400, 0x10428 },  /* upper */
  { 0x10401, 0x10429 },  /* upper */
  { 0x10402, 0x1042a },  /* upper */
  { 0x10403, 0x1042b },  /* upper */
  { 0x10404, 0x1042c },  /* upper */
  { 0x10405, 0x1042d },  /* upper */
  { 0x10406, 0x1042e },  /* upper */
  { 0x10407, 0x1042f },  /* upper */
  { 0x10408, 0x10430 },  /* upper */
  { 0x10409, 0x10431 },  /* upper */
  { 0x1040a, 0x10432 },  /* upper */
  { 0x1040b, 0x10433 },  /* upper */
  { 0x1040c, 0x10434 },  /* upper */
  { 0x1040d, 0x10435 },  /* upper */
  { 0x1040e, 0x10436 },  /* upper */
  { 0x1040f, 0x10437 },  /* upper */
  { 0x10410, 0x10438 },  /* upper */
  { 0x10411, 0x10439 },  /* upper */
  { 0x10412, 0x1043a },  /* upper */
  { 0x10413, 0x1043b },  /* upper */
  { 0x10414, 0x1043c },  /* upper */
  { 0x10415, 0x1043d },  /* upper */
  { 0x10416, 0x1043e },  /* upper */
  { 0x10417, 0x1043f },  /* upper */
  { 0x10418, 0x10440 },  /* upper */
  { 0x10419, 0x10441 },  /* upper */
  { 0x1041a, 0x10442 },  /* upper */
  { 0x1041b, 0x10443 },  /* upper */
  { 0x1041c, 0x10444 },  /* upper */
  { 0x1041d, 0x10445 },  /* upper */
  { 0x1041e, 0x10446 },  /* upper */
  { 0x1041f, 0x10447 },  /* upper */
  { 0x10420, 0x10448 },  /* upper */
  { 0x10421, 0x10449 },  /* upper */
  { 0x10422, 0x1044a },  /* upper */
  { 0x10423, 0x1044b },  /* upper */
  { 0x10424, 0x1044c },  /* upper */
  { 0x10425, 0x1044d },  /* upper */
  { 0x10426, 0x1044e },  /* upper */
  { 0x10427, 0x1044f },  /* upper */
  { 0x10400, 0x10428 },  /* lower */
  { 0x10401, 0x10429 },  /* lower */
  { 0x10402, 0x1042a },  /* lower */
  { 0x10403, 0x1042b },  /* lower */
  { 0x10404, 0x1042c },  /* lower */
  { 0x10405, 0x1042d },  /* lower */
  { 0x10406, 0x1042e },  /* lower */
  { 0x10407, 0x1042f },  /* lower */
  { 0x10408, 0x10430 },  /* lower */
  { 0x10409, 0x10431 },  /* lower */
  { 0x1040a, 0x10432 },  /* lower */
  { 0x1040b, 0x10433 },  /* lower */
  { 0x1040c, 0x10434 },  /* lower */
  { 0x1040d, 0x10435 },  /* lower */
  { 0x1040e, 0x10436 },  /* lower */
  { 0x1040f, 0x10437 },  /* lower */
  { 0x10410, 0x10438 },  /* lower */
  { 0x10411, 0x10439 },  /* lower */
  { 0x10412, 0x1043a },  /* lower */
  { 0x10413, 0x1043b },  /* lower */
  { 0x10414, 0x1043c },  /* lower */
  { 0x10415, 0x1043d },  /* lower */
  { 0x10416, 0x1043e },  /* lower */
  { 0x10417, 0x1043f },  /* lower */
  { 0x10418, 0x10440 },  /* lower */
  { 0x10419, 0x10441 },  /* lower */
  { 0x1041a, 0x10442 },  /* lower */
  { 0x1041b, 0x10443 },  /* lower */
  { 0x1041c, 0x10444 },  /* lower */
  { 0x1041d, 0x10445 },  /* lower */
  { 0x1041e, 0x10446 },  /* lower */
  { 0x1041f, 0x10447 },  /* lower */
  { 0x10420, 0x10448 },  /* lower */
  { 0x10421, 0x10449 },  /* lower */
  { 0x10422, 0x1044a },  /* lower */
  { 0x10423, 0x1044b },  /* lower */
  { 0x10424, 0x1044c },  /* lower */
  { 0x10425, 0x1044d },  /* lower */
  { 0x10426, 0x1044e },  /* lower */
  { 0x10427, 0x1044f },  /* lower */
  { 0x10450, 0x10450 },
  { 0x10451, 0x10451 },
  { 0x10452, 0x10452 },
  { 0x10453, 0x10453 },
  { 0x10454, 0x10454 },
  { 0x10455, 0x10455 },
  { 0x10456, 0x10456 },
  { 0x10457, 0x10457 },
  { 0x10458, 0x10458 },
  { 0x10459, 0x10459 },
  { 0x1045a, 0x1045a },
  { 0x1045b, 0x1045b },
  { 0x1045c, 0x1045c },
  { 0x1045d, 0x1045d },
  { 0x1045e, 0x1045e },
  { 0x1045f, 0x1045f },
  { 0x10460, 0x10460 },
  { 0x10461, 0x10461 },
  { 0x10462, 0x10462 },
  { 0x10463, 0x10463 },
  { 0x10464, 0x10464 },
  { 0x10465, 0x10465 },
  { 0x10466, 0x10466 },
  { 0x10467, 0x10467 },
  { 0x10468, 0x10468 },
  { 0x10469, 0x10469 },
  { 0x1046a, 0x1046a },
  { 0x1046b, 0x1046b },
  { 0x1046c, 0x1046c },
  { 0x1046d, 0x1046d },
  { 0x1046e, 0x1046e },
  { 0x1046f, 0x1046f },
  { 0x10470, 0x10470 },
  { 0x10471, 0x10471 },
  { 0x10472, 0x10472 },
  { 0x10473, 0x10473 },
  { 0x10474, 0x10474 },
  { 0x10475, 0x10475 },
  { 0x10476, 0x10476 },
  { 0x10477, 0x10477 },
  { 0x10478, 0x10478 },
  { 0x10479, 0x10479 },
  { 0x1047a, 0x1047a },
  { 0x1047b, 0x1047b },
  { 0x1047c, 0x1047c },
  { 0x1047d, 0x1047d },
  { 0x1047e, 0x1047e },
  { 0x1047f, 0x1047f },
  { 0x10480, 0x10480 },
  { 0x10481, 0x10481 },
  { 0x10482, 0x10482 },
  { 0x10483, 0x10483 },
  { 0x10484, 0x10484 },
  { 0x10485, 0x10485 },
  { 0x10486, 0x10486 },
  { 0x10487, 0x10487 },
  { 0x10488, 0x10488 },
  { 0x10489, 0x10489 },
  { 0x1048a, 0x1048a },
  { 0x1048b, 0x1048b },
  { 0x1048c, 0x1048c },
  { 0x1048d, 0x1048d },
  { 0x1048e, 0x1048e },
  { 0x1048f, 0x1048f },
  { 0x10490, 0x10490 },
  { 0x10491, 0x10491 },
  { 0x10492, 0x10492 },
  { 0x10493, 0x10493 },
  { 0x10494, 0x10494 },
  { 0x10495, 0x10495 },
  { 0x10496, 0x10496 },
  { 0x10497, 0x10497 },
  { 0x10498, 0x10498 },
  { 0x10499, 0x10499 },
  { 0x1049a, 0x1049a },
  { 0x1049b, 0x1049b },
  { 0x1049c, 0x1049c },
  { 0x1049d, 0x1049d },
  { 0x1049e, 0x1049e },
  { 0x1049f, 0x1049f },
  { 0x104a0, 0x104a0 },
  { 0x104a1, 0x104a1 },
  { 0x104a2, 0x104a2 },
  { 0x104a3, 0x104a3 },
  { 0x104a4, 0x104a4 },
  { 0x104a5, 0x104a5 },
  { 0x104a6, 0x104a6 },
  { 0x104a7, 0x104a7 },
  { 0x104a8, 0x104a8 },
  { 0x104a9, 0x104a9 },
  { 0x104aa, 0x104aa },
  { 0x104ab, 0x104ab },
  { 0x104ac, 0x104ac },
  { 0x104ad, 0x104ad },
  { 0x104ae, 0x104ae },
  { 0x104af, 0x104af },
  { 0x104b0, 0x104b0 },
  { 0x104b1, 0x104b1 },
  { 0x104b2, 0x104b2 },
  { 0x104b3, 0x104b3 },
  { 0x104b4, 0x104b4 },
  { 0x104b5, 0x104b5 },
  { 0x104b6, 0x104b6 },
  { 0x104b7, 0x104b7 },
  { 0x104b8, 0x104b8 },
  { 0x104b9, 0x104b9 },
  { 0x104ba, 0x104ba },
  { 0x104bb, 0x104bb },
  { 0x104bc, 0x104bc },
  { 0x104bd, 0x104bd },
  { 0x104be, 0x104be },
  { 0x104bf, 0x104bf },
  { 0x104c0, 0x104c0 },
  { 0x104c1, 0x104c1 },
  { 0x104c2, 0x104c2 },
  { 0x104c3, 0x104c3 },
  { 0x104c4, 0x104c4 },
  { 0x104c5, 0x104c5 },
  { 0x104c6, 0x104c6 },
  { 0x104c7, 0x104c7 },
  { 0x104c8, 0x104c8 },
  { 0x104c9, 0x104c9 },
  { 0x104ca, 0x104ca },
  { 0x104cb, 0x104cb },
  { 0x104cc, 0x104cc },
  { 0x104cd, 0x104cd },
  { 0x104ce, 0x104ce },
  { 0x104cf, 0x104cf },
  { 0x104d0, 0x104d0 },
  { 0x104d1, 0x104d1 },
  { 0x104d2, 0x104d2 },
  { 0x104d3, 0x104d3 },
  { 0x104d4, 0x104d4 },
  { 0x104d5, 0x104d5 },
  { 0x104d6, 0x104d6 },
  { 0x104d7, 0x104d7 },
  { 0x104d8, 0x104d8 },
  { 0x104d9, 0x104d9 },
  { 0x104da, 0x104da },
  { 0x104db, 0x104db },
  { 0x104dc, 0x104dc },
  { 0x104dd, 0x104dd },
  { 0x104de, 0x104de },
  { 0x104df, 0x104df },
  { 0x104e0, 0x104e0 },
  { 0x104e1, 0x104e1 },
  { 0x104e2, 0x104e2 },
  { 0x104e3, 0x104e3 },
  { 0x104e4, 0x104e4 },
  { 0x104e5, 0x104e5 },
  { 0x104e6, 0x104e6 },
  { 0x104e7, 0x104e7 },
  { 0x104e8, 0x104e8 },
  { 0x104e9, 0x104e9 },
  { 0x104ea, 0x104ea },
  { 0x104eb, 0x104eb },
  { 0x104ec, 0x104ec },
  { 0x104ed, 0x104ed },
  { 0x104ee, 0x104ee },
  { 0x104ef, 0x104ef },
  { 0x104f0, 0x104f0 },
  { 0x104f1, 0x104f1 },
  { 0x104f2, 0x104f2 },
  { 0x104f3, 0x104f3 },
  { 0x104f4, 0x104f4 },
  { 0x104f5, 0x104f5 },
  { 0x104f6, 0x104f6 },
  { 0x104f7, 0x104f7 },
  { 0x104f8, 0x104f8 },
  { 0x104f9, 0x104f9 },
  { 0x104fa, 0x104fa },
  { 0x104fb, 0x104fb },
  { 0x104fc, 0x104fc },
  { 0x104fd, 0x104fd },
  { 0x104fe, 0x104fe },
  { 0x104ff, 0x104ff },
};

static void get_case_block(glui32 ch, case_block_t **blockptr)
{
  switch (ch >> 8)
  {
  case 0x0:
    *blockptr = unigen_case_block_0x0;
    break;
  case 0x1:
    *blockptr = unigen_case_block_0x1;
    break;
  case 0x2:
    *blockptr = unigen_case_block_0x2;
    break;
  case 0x3:
    *blockptr = unigen_case_block_0x3;
    break;
  case 0x4:
    *blockptr = unigen_case_block_0x4;
    break;
  case 0x5:
    *blockptr = unigen_case_block_0x5;
    break;
  case 0x1e:
    *blockptr = unigen_case_block_0x1e;
    break;
  case 0x1f:
    *blockptr = unigen_case_block_0x1f;
    break;
  case 0x21:
    *blockptr = unigen_case_block_0x21;
    break;
  case 0x24:
    *blockptr = unigen_case_block_0x24;
    break;
  case 0xfb:
    *blockptr = unigen_case_block_0xfb;
    break;
  case 0xff:
    *blockptr = unigen_case_block_0xff;
    break;
  case 0x104:
    *blockptr = unigen_case_block_0x104;
    break;
  default:
    *blockptr = NULL;
    break;
  }
}

glui32 unigen_special_array[] = {
  2, 0x53, 0x53,  /* 0xdf upcase */
  1, 0xdf,  /* 0xdf downcase */
  2, 0x53, 0x73,  /* 0xdf titlecase */
  1, 0x130,  /* 0x130 upcase */
  2, 0x69, 0x307,  /* 0x130 downcase */
  1, 0x130,  /* 0x130 titlecase */
  2, 0x2bc, 0x4e,  /* 0x149 upcase */
  1, 0x149,  /* 0x149 downcase */
  2, 0x2bc, 0x4e,  /* 0x149 titlecase */
  1, 0x1c4,  /* 0x1c4 upcase */
  1, 0x1c6,  /* 0x1c4 downcase */
  1, 0x1c5,  /* 0x1c4 titlecase */
  1, 0x1c4,  /* 0x1c5 upcase */
  1, 0x1c6,  /* 0x1c5 downcase */
  1, 0x1c5,  /* 0x1c5 titlecase */
  1, 0x1c4,  /* 0x1c6 upcase */
  1, 0x1c6,  /* 0x1c6 downcase */
  1, 0x1c5,  /* 0x1c6 titlecase */
  1, 0x1c7,  /* 0x1c7 upcase */
  1, 0x1c9,  /* 0x1c7 downcase */
  1, 0x1c8,  /* 0x1c7 titlecase */
  1, 0x1c7,  /* 0x1c8 upcase */
  1, 0x1c9,  /* 0x1c8 downcase */
  1, 0x1c8,  /* 0x1c8 titlecase */
  1, 0x1c7,  /* 0x1c9 upcase */
  1, 0x1c9,  /* 0x1c9 downcase */
  1, 0x1c8,  /* 0x1c9 titlecase */
  1, 0x1ca,  /* 0x1ca upcase */
  1, 0x1cc,  /* 0x1ca downcase */
  1, 0x1cb,  /* 0x1ca titlecase */
  1, 0x1ca,  /* 0x1cb upcase */
  1, 0x1cc,  /* 0x1cb downcase */
  1, 0x1cb,  /* 0x1cb titlecase */
  1, 0x1ca,  /* 0x1cc upcase */
  1, 0x1cc,  /* 0x1cc downcase */
  1, 0x1cb,  /* 0x1cc titlecase */
  2, 0x4a, 0x30c,  /* 0x1f0 upcase */
  1, 0x1f0,  /* 0x1f0 downcase */
  2, 0x4a, 0x30c,  /* 0x1f0 titlecase */
  1, 0x1f1,  /* 0x1f1 upcase */
  1, 0x1f3,  /* 0x1f1 downcase */
  1, 0x1f2,  /* 0x1f1 titlecase */
  1, 0x1f1,  /* 0x1f2 upcase */
  1, 0x1f3,  /* 0x1f2 downcase */
  1, 0x1f2,  /* 0x1f2 titlecase */
  1, 0x1f1,  /* 0x1f3 upcase */
  1, 0x1f3,  /* 0x1f3 downcase */
  1, 0x1f2,  /* 0x1f3 titlecase */
  3, 0x399, 0x308, 0x301,  /* 0x390 upcase */
  1, 0x390,  /* 0x390 downcase */
  3, 0x399, 0x308, 0x301,  /* 0x390 titlecase */
  3, 0x3a5, 0x308, 0x301,  /* 0x3b0 upcase */
  1, 0x3b0,  /* 0x3b0 downcase */
  3, 0x3a5, 0x308, 0x301,  /* 0x3b0 titlecase */
  2, 0x535, 0x552,  /* 0x587 upcase */
  1, 0x587,  /* 0x587 downcase */
  2, 0x535, 0x582,  /* 0x587 titlecase */
  2, 0x48, 0x331,  /* 0x1e96 upcase */
  1, 0x1e96,  /* 0x1e96 downcase */
  2, 0x48, 0x331,  /* 0x1e96 titlecase */
  2, 0x54, 0x308,  /* 0x1e97 upcase */
  1, 0x1e97,  /* 0x1e97 downcase */
  2, 0x54, 0x308,  /* 0x1e97 titlecase */
  2, 0x57, 0x30a,  /* 0x1e98 upcase */
  1, 0x1e98,  /* 0x1e98 downcase */
  2, 0x57, 0x30a,  /* 0x1e98 titlecase */
  2, 0x59, 0x30a,  /* 0x1e99 upcase */
  1, 0x1e99,  /* 0x1e99 downcase */
  2, 0x59, 0x30a,  /* 0x1e99 titlecase */
  2, 0x41, 0x2be,  /* 0x1e9a upcase */
  1, 0x1e9a,  /* 0x1e9a downcase */
  2, 0x41, 0x2be,  /* 0x1e9a titlecase */
  2, 0x3a5, 0x313,  /* 0x1f50 upcase */
  1, 0x1f50,  /* 0x1f50 downcase */
  2, 0x3a5, 0x313,  /* 0x1f50 titlecase */
  3, 0x3a5, 0x313, 0x300,  /* 0x1f52 upcase */
  1, 0x1f52,  /* 0x1f52 downcase */
  3, 0x3a5, 0x313, 0x300,  /* 0x1f52 titlecase */
  3, 0x3a5, 0x313, 0x301,  /* 0x1f54 upcase */
  1, 0x1f54,  /* 0x1f54 downcase */
  3, 0x3a5, 0x313, 0x301,  /* 0x1f54 titlecase */
  3, 0x3a5, 0x313, 0x342,  /* 0x1f56 upcase */
  1, 0x1f56,  /* 0x1f56 downcase */
  3, 0x3a5, 0x313, 0x342,  /* 0x1f56 titlecase */
  2, 0x1f08, 0x399,  /* 0x1f80 upcase */
  1, 0x1f80,  /* 0x1f80 downcase */
  1, 0x1f88,  /* 0x1f80 titlecase */
  2, 0x1f09, 0x399,  /* 0x1f81 upcase */
  1, 0x1f81,  /* 0x1f81 downcase */
  1, 0x1f89,  /* 0x1f81 titlecase */
  2, 0x1f0a, 0x399,  /* 0x1f82 upcase */
  1, 0x1f82,  /* 0x1f82 downcase */
  1, 0x1f8a,  /* 0x1f82 titlecase */
  2, 0x1f0b, 0x399,  /* 0x1f83 upcase */
  1, 0x1f83,  /* 0x1f83 downcase */
  1, 0x1f8b,  /* 0x1f83 titlecase */
  2, 0x1f0c, 0x399,  /* 0x1f84 upcase */
  1, 0x1f84,  /* 0x1f84 downcase */
  1, 0x1f8c,  /* 0x1f84 titlecase */
  2, 0x1f0d, 0x399,  /* 0x1f85 upcase */
  1, 0x1f85,  /* 0x1f85 downcase */
  1, 0x1f8d,  /* 0x1f85 titlecase */
  2, 0x1f0e, 0x399,  /* 0x1f86 upcase */
  1, 0x1f86,  /* 0x1f86 downcase */
  1, 0x1f8e,  /* 0x1f86 titlecase */
  2, 0x1f0f, 0x399,  /* 0x1f87 upcase */
  1, 0x1f87,  /* 0x1f87 downcase */
  1, 0x1f8f,  /* 0x1f87 titlecase */
  2, 0x1f08, 0x399,  /* 0x1f88 upcase */
  1, 0x1f80,  /* 0x1f88 downcase */
  1, 0x1f88,  /* 0x1f88 titlecase */
  2, 0x1f09, 0x399,  /* 0x1f89 upcase */
  1, 0x1f81,  /* 0x1f89 downcase */
  1, 0x1f89,  /* 0x1f89 titlecase */
  2, 0x1f0a, 0x399,  /* 0x1f8a upcase */
  1, 0x1f82,  /* 0x1f8a downcase */
  1, 0x1f8a,  /* 0x1f8a titlecase */
  2, 0x1f0b, 0x399,  /* 0x1f8b upcase */
  1, 0x1f83,  /* 0x1f8b downcase */
  1, 0x1f8b,  /* 0x1f8b titlecase */
  2, 0x1f0c, 0x399,  /* 0x1f8c upcase */
  1, 0x1f84,  /* 0x1f8c downcase */
  1, 0x1f8c,  /* 0x1f8c titlecase */
  2, 0x1f0d, 0x399,  /* 0x1f8d upcase */
  1, 0x1f85,  /* 0x1f8d downcase */
  1, 0x1f8d,  /* 0x1f8d titlecase */
  2, 0x1f0e, 0x399,  /* 0x1f8e upcase */
  1, 0x1f86,  /* 0x1f8e downcase */
  1, 0x1f8e,  /* 0x1f8e titlecase */
  2, 0x1f0f, 0x399,  /* 0x1f8f upcase */
  1, 0x1f87,  /* 0x1f8f downcase */
  1, 0x1f8f,  /* 0x1f8f titlecase */
  2, 0x1f28, 0x399,  /* 0x1f90 upcase */
  1, 0x1f90,  /* 0x1f90 downcase */
  1, 0x1f98,  /* 0x1f90 titlecase */
  2, 0x1f29, 0x399,  /* 0x1f91 upcase */
  1, 0x1f91,  /* 0x1f91 downcase */
  1, 0x1f99,  /* 0x1f91 titlecase */
  2, 0x1f2a, 0x399,  /* 0x1f92 upcase */
  1, 0x1f92,  /* 0x1f92 downcase */
  1, 0x1f9a,  /* 0x1f92 titlecase */
  2, 0x1f2b, 0x399,  /* 0x1f93 upcase */
  1, 0x1f93,  /* 0x1f93 downcase */
  1, 0x1f9b,  /* 0x1f93 titlecase */
  2, 0x1f2c, 0x399,  /* 0x1f94 upcase */
  1, 0x1f94,  /* 0x1f94 downcase */
  1, 0x1f9c,  /* 0x1f94 titlecase */
  2, 0x1f2d, 0x399,  /* 0x1f95 upcase */
  1, 0x1f95,  /* 0x1f95 downcase */
  1, 0x1f9d,  /* 0x1f95 titlecase */
  2, 0x1f2e, 0x399,  /* 0x1f96 upcase */
  1, 0x1f96,  /* 0x1f96 downcase */
  1, 0x1f9e,  /* 0x1f96 titlecase */
  2, 0x1f2f, 0x399,  /* 0x1f97 upcase */
  1, 0x1f97,  /* 0x1f97 downcase */
  1, 0x1f9f,  /* 0x1f97 titlecase */
  2, 0x1f28, 0x399,  /* 0x1f98 upcase */
  1, 0x1f90,  /* 0x1f98 downcase */
  1, 0x1f98,  /* 0x1f98 titlecase */
  2, 0x1f29, 0x399,  /* 0x1f99 upcase */
  1, 0x1f91,  /* 0x1f99 downcase */
  1, 0x1f99,  /* 0x1f99 titlecase */
  2, 0x1f2a, 0x399,  /* 0x1f9a upcase */
  1, 0x1f92,  /* 0x1f9a downcase */
  1, 0x1f9a,  /* 0x1f9a titlecase */
  2, 0x1f2b, 0x399,  /* 0x1f9b upcase */
  1, 0x1f93,  /* 0x1f9b downcase */
  1, 0x1f9b,  /* 0x1f9b titlecase */
  2, 0x1f2c, 0x399,  /* 0x1f9c upcase */
  1, 0x1f94,  /* 0x1f9c downcase */
  1, 0x1f9c,  /* 0x1f9c titlecase */
  2, 0x1f2d, 0x399,  /* 0x1f9d upcase */
  1, 0x1f95,  /* 0x1f9d downcase */
  1, 0x1f9d,  /* 0x1f9d titlecase */
  2, 0x1f2e, 0x399,  /* 0x1f9e upcase */
  1, 0x1f96,  /* 0x1f9e downcase */
  1, 0x1f9e,  /* 0x1f9e titlecase */
  2, 0x1f2f, 0x399,  /* 0x1f9f upcase */
  1, 0x1f97,  /* 0x1f9f downcase */
  1, 0x1f9f,  /* 0x1f9f titlecase */
  2, 0x1f68, 0x399,  /* 0x1fa0 upcase */
  1, 0x1fa0,  /* 0x1fa0 downcase */
  1, 0x1fa8,  /* 0x1fa0 titlecase */
  2, 0x1f69, 0x399,  /* 0x1fa1 upcase */
  1, 0x1fa1,  /* 0x1fa1 downcase */
  1, 0x1fa9,  /* 0x1fa1 titlecase */
  2, 0x1f6a, 0x399,  /* 0x1fa2 upcase */
  1, 0x1fa2,  /* 0x1fa2 downcase */
  1, 0x1faa,  /* 0x1fa2 titlecase */
  2, 0x1f6b, 0x399,  /* 0x1fa3 upcase */
  1, 0x1fa3,  /* 0x1fa3 downcase */
  1, 0x1fab,  /* 0x1fa3 titlecase */
  2, 0x1f6c, 0x399,  /* 0x1fa4 upcase */
  1, 0x1fa4,  /* 0x1fa4 downcase */
  1, 0x1fac,  /* 0x1fa4 titlecase */
  2, 0x1f6d, 0x399,  /* 0x1fa5 upcase */
  1, 0x1fa5,  /* 0x1fa5 downcase */
  1, 0x1fad,  /* 0x1fa5 titlecase */
  2, 0x1f6e, 0x399,  /* 0x1fa6 upcase */
  1, 0x1fa6,  /* 0x1fa6 downcase */
  1, 0x1fae,  /* 0x1fa6 titlecase */
  2, 0x1f6f, 0x399,  /* 0x1fa7 upcase */
  1, 0x1fa7,  /* 0x1fa7 downcase */
  1, 0x1faf,  /* 0x1fa7 titlecase */
  2, 0x1f68, 0x399,  /* 0x1fa8 upcase */
  1, 0x1fa0,  /* 0x1fa8 downcase */
  1, 0x1fa8,  /* 0x1fa8 titlecase */
  2, 0x1f69, 0x399,  /* 0x1fa9 upcase */
  1, 0x1fa1,  /* 0x1fa9 downcase */
  1, 0x1fa9,  /* 0x1fa9 titlecase */
  2, 0x1f6a, 0x399,  /* 0x1faa upcase */
  1, 0x1fa2,  /* 0x1faa downcase */
  1, 0x1faa,  /* 0x1faa titlecase */
  2, 0x1f6b, 0x399,  /* 0x1fab upcase */
  1, 0x1fa3,  /* 0x1fab downcase */
  1, 0x1fab,  /* 0x1fab titlecase */
  2, 0x1f6c, 0x399,  /* 0x1fac upcase */
  1, 0x1fa4,  /* 0x1fac downcase */
  1, 0x1fac,  /* 0x1fac titlecase */
  2, 0x1f6d, 0x399,  /* 0x1fad upcase */
  1, 0x1fa5,  /* 0x1fad downcase */
  1, 0x1fad,  /* 0x1fad titlecase */
  2, 0x1f6e, 0x399,  /* 0x1fae upcase */
  1, 0x1fa6,  /* 0x1fae downcase */
  1, 0x1fae,  /* 0x1fae titlecase */
  2, 0x1f6f, 0x399,  /* 0x1faf upcase */
  1, 0x1fa7,  /* 0x1faf downcase */
  1, 0x1faf,  /* 0x1faf titlecase */
  2, 0x1fba, 0x399,  /* 0x1fb2 upcase */
  1, 0x1fb2,  /* 0x1fb2 downcase */
  2, 0x1fba, 0x345,  /* 0x1fb2 titlecase */
  2, 0x391, 0x399,  /* 0x1fb3 upcase */
  1, 0x1fb3,  /* 0x1fb3 downcase */
  1, 0x1fbc,  /* 0x1fb3 titlecase */
  2, 0x386, 0x399,  /* 0x1fb4 upcase */
  1, 0x1fb4,  /* 0x1fb4 downcase */
  2, 0x386, 0x345,  /* 0x1fb4 titlecase */
  2, 0x391, 0x342,  /* 0x1fb6 upcase */
  1, 0x1fb6,  /* 0x1fb6 downcase */
  2, 0x391, 0x342,  /* 0x1fb6 titlecase */
  3, 0x391, 0x342, 0x399,  /* 0x1fb7 upcase */
  1, 0x1fb7,  /* 0x1fb7 downcase */
  3, 0x391, 0x342, 0x345,  /* 0x1fb7 titlecase */
  2, 0x391, 0x399,  /* 0x1fbc upcase */
  1, 0x1fb3,  /* 0x1fbc downcase */
  1, 0x1fbc,  /* 0x1fbc titlecase */
  2, 0x1fca, 0x399,  /* 0x1fc2 upcase */
  1, 0x1fc2,  /* 0x1fc2 downcase */
  2, 0x1fca, 0x345,  /* 0x1fc2 titlecase */
  2, 0x397, 0x399,  /* 0x1fc3 upcase */
  1, 0x1fc3,  /* 0x1fc3 downcase */
  1, 0x1fcc,  /* 0x1fc3 titlecase */
  2, 0x389, 0x399,  /* 0x1fc4 upcase */
  1, 0x1fc4,  /* 0x1fc4 downcase */
  2, 0x389, 0x345,  /* 0x1fc4 titlecase */
  2, 0x397, 0x342,  /* 0x1fc6 upcase */
  1, 0x1fc6,  /* 0x1fc6 downcase */
  2, 0x397, 0x342,  /* 0x1fc6 titlecase */
  3, 0x397, 0x342, 0x399,  /* 0x1fc7 upcase */
  1, 0x1fc7,  /* 0x1fc7 downcase */
  3, 0x397, 0x342, 0x345,  /* 0x1fc7 titlecase */
  2, 0x397, 0x399,  /* 0x1fcc upcase */
  1, 0x1fc3,  /* 0x1fcc downcase */
  1, 0x1fcc,  /* 0x1fcc titlecase */
  3, 0x399, 0x308, 0x300,  /* 0x1fd2 upcase */
  1, 0x1fd2,  /* 0x1fd2 downcase */
  3, 0x399, 0x308, 0x300,  /* 0x1fd2 titlecase */
  3, 0x399, 0x308, 0x301,  /* 0x1fd3 upcase */
  1, 0x1fd3,  /* 0x1fd3 downcase */
  3, 0x399, 0x308, 0x301,  /* 0x1fd3 titlecase */
  2, 0x399, 0x342,  /* 0x1fd6 upcase */
  1, 0x1fd6,  /* 0x1fd6 downcase */
  2, 0x399, 0x342,  /* 0x1fd6 titlecase */
  3, 0x399, 0x308, 0x342,  /* 0x1fd7 upcase */
  1, 0x1fd7,  /* 0x1fd7 downcase */
  3, 0x399, 0x308, 0x342,  /* 0x1fd7 titlecase */
  3, 0x3a5, 0x308, 0x300,  /* 0x1fe2 upcase */
  1, 0x1fe2,  /* 0x1fe2 downcase */
  3, 0x3a5, 0x308, 0x300,  /* 0x1fe2 titlecase */
  3, 0x3a5, 0x308, 0x301,  /* 0x1fe3 upcase */
  1, 0x1fe3,  /* 0x1fe3 downcase */
  3, 0x3a5, 0x308, 0x301,  /* 0x1fe3 titlecase */
  2, 0x3a1, 0x313,  /* 0x1fe4 upcase */
  1, 0x1fe4,  /* 0x1fe4 downcase */
  2, 0x3a1, 0x313,  /* 0x1fe4 titlecase */
  2, 0x3a5, 0x342,  /* 0x1fe6 upcase */
  1, 0x1fe6,  /* 0x1fe6 downcase */
  2, 0x3a5, 0x342,  /* 0x1fe6 titlecase */
  3, 0x3a5, 0x308, 0x342,  /* 0x1fe7 upcase */
  1, 0x1fe7,  /* 0x1fe7 downcase */
  3, 0x3a5, 0x308, 0x342,  /* 0x1fe7 titlecase */
  2, 0x1ffa, 0x399,  /* 0x1ff2 upcase */
  1, 0x1ff2,  /* 0x1ff2 downcase */
  2, 0x1ffa, 0x345,  /* 0x1ff2 titlecase */
  2, 0x3a9, 0x399,  /* 0x1ff3 upcase */
  1, 0x1ff3,  /* 0x1ff3 downcase */
  1, 0x1ffc,  /* 0x1ff3 titlecase */
  2, 0x38f, 0x399,  /* 0x1ff4 upcase */
  1, 0x1ff4,  /* 0x1ff4 downcase */
  2, 0x38f, 0x345,  /* 0x1ff4 titlecase */
  2, 0x3a9, 0x342,  /* 0x1ff6 upcase */
  1, 0x1ff6,  /* 0x1ff6 downcase */
  2, 0x3a9, 0x342,  /* 0x1ff6 titlecase */
  3, 0x3a9, 0x342, 0x399,  /* 0x1ff7 upcase */
  1, 0x1ff7,  /* 0x1ff7 downcase */
  3, 0x3a9, 0x342, 0x345,  /* 0x1ff7 titlecase */
  2, 0x3a9, 0x399,  /* 0x1ffc upcase */
  1, 0x1ff3,  /* 0x1ffc downcase */
  1, 0x1ffc,  /* 0x1ffc titlecase */
  2, 0x46, 0x46,  /* 0xfb00 upcase */
  1, 0xfb00,  /* 0xfb00 downcase */
  2, 0x46, 0x66,  /* 0xfb00 titlecase */
  2, 0x46, 0x49,  /* 0xfb01 upcase */
  1, 0xfb01,  /* 0xfb01 downcase */
  2, 0x46, 0x69,  /* 0xfb01 titlecase */
  2, 0x46, 0x4c,  /* 0xfb02 upcase */
  1, 0xfb02,  /* 0xfb02 downcase */
  2, 0x46, 0x6c,  /* 0xfb02 titlecase */
  3, 0x46, 0x46, 0x49,  /* 0xfb03 upcase */
  1, 0xfb03,  /* 0xfb03 downcase */
  3, 0x46, 0x66, 0x69,  /* 0xfb03 titlecase */
  3, 0x46, 0x46, 0x4c,  /* 0xfb04 upcase */
  1, 0xfb04,  /* 0xfb04 downcase */
  3, 0x46, 0x66, 0x6c,  /* 0xfb04 titlecase */
  2, 0x53, 0x54,  /* 0xfb05 upcase */
  1, 0xfb05,  /* 0xfb05 downcase */
  2, 0x53, 0x74,  /* 0xfb05 titlecase */
  2, 0x53, 0x54,  /* 0xfb06 upcase */
  1, 0xfb06,  /* 0xfb06 downcase */
  2, 0x53, 0x74,  /* 0xfb06 titlecase */
  2, 0x544, 0x546,  /* 0xfb13 upcase */
  1, 0xfb13,  /* 0xfb13 downcase */
  2, 0x544, 0x576,  /* 0xfb13 titlecase */
  2, 0x544, 0x535,  /* 0xfb14 upcase */
  1, 0xfb14,  /* 0xfb14 downcase */
  2, 0x544, 0x565,  /* 0xfb14 titlecase */
  2, 0x544, 0x53b,  /* 0xfb15 upcase */
  1, 0xfb15,  /* 0xfb15 downcase */
  2, 0x544, 0x56b,  /* 0xfb15 titlecase */
  2, 0x54e, 0x546,  /* 0xfb16 upcase */
  1, 0xfb16,  /* 0xfb16 downcase */
  2, 0x54e, 0x576,  /* 0xfb16 titlecase */
  2, 0x544, 0x53d,  /* 0xfb17 upcase */
  1, 0xfb17,  /* 0xfb17 downcase */
  2, 0x544, 0x56d,  /* 0xfb17 titlecase */
};

case_special_t unigen_special_0xdf = { 0, 3, 5 };
case_special_t unigen_special_0x130 = { 8, 10, 13 };
case_special_t unigen_special_0x149 = { 15, 18, 20 };
case_special_t unigen_special_0x1c4 = { 23, 25, 27 };
case_special_t unigen_special_0x1c5 = { 29, 31, 33 };
case_special_t unigen_special_0x1c6 = { 35, 37, 39 };
case_special_t unigen_special_0x1c7 = { 41, 43, 45 };
case_special_t unigen_special_0x1c8 = { 47, 49, 51 };
case_special_t unigen_special_0x1c9 = { 53, 55, 57 };
case_special_t unigen_special_0x1ca = { 59, 61, 63 };
case_special_t unigen_special_0x1cb = { 65, 67, 69 };
case_special_t unigen_special_0x1cc = { 71, 73, 75 };
case_special_t unigen_special_0x1f0 = { 77, 80, 82 };
case_special_t unigen_special_0x1f1 = { 85, 87, 89 };
case_special_t unigen_special_0x1f2 = { 91, 93, 95 };
case_special_t unigen_special_0x1f3 = { 97, 99, 101 };
case_special_t unigen_special_0x390 = { 103, 107, 109 };
case_special_t unigen_special_0x3b0 = { 113, 117, 119 };
case_special_t unigen_special_0x587 = { 123, 126, 128 };
case_special_t unigen_special_0x1e96 = { 131, 134, 136 };
case_special_t unigen_special_0x1e97 = { 139, 142, 144 };
case_special_t unigen_special_0x1e98 = { 147, 150, 152 };
case_special_t unigen_special_0x1e99 = { 155, 158, 160 };
case_special_t unigen_special_0x1e9a = { 163, 166, 168 };
case_special_t unigen_special_0x1f50 = { 171, 174, 176 };
case_special_t unigen_special_0x1f52 = { 179, 183, 185 };
case_special_t unigen_special_0x1f54 = { 189, 193, 195 };
case_special_t unigen_special_0x1f56 = { 199, 203, 205 };
case_special_t unigen_special_0x1f80 = { 209, 212, 214 };
case_special_t unigen_special_0x1f81 = { 216, 219, 221 };
case_special_t unigen_special_0x1f82 = { 223, 226, 228 };
case_special_t unigen_special_0x1f83 = { 230, 233, 235 };
case_special_t unigen_special_0x1f84 = { 237, 240, 242 };
case_special_t unigen_special_0x1f85 = { 244, 247, 249 };
case_special_t unigen_special_0x1f86 = { 251, 254, 256 };
case_special_t unigen_special_0x1f87 = { 258, 261, 263 };
case_special_t unigen_special_0x1f88 = { 265, 268, 270 };
case_special_t unigen_special_0x1f89 = { 272, 275, 277 };
case_special_t unigen_special_0x1f8a = { 279, 282, 284 };
case_special_t unigen_special_0x1f8b = { 286, 289, 291 };
case_special_t unigen_special_0x1f8c = { 293, 296, 298 };
case_special_t unigen_special_0x1f8d = { 300, 303, 305 };
case_special_t unigen_special_0x1f8e = { 307, 310, 312 };
case_special_t unigen_special_0x1f8f = { 314, 317, 319 };
case_special_t unigen_special_0x1f90 = { 321, 324, 326 };
case_special_t unigen_special_0x1f91 = { 328, 331, 333 };
case_special_t unigen_special_0x1f92 = { 335, 338, 340 };
case_special_t unigen_special_0x1f93 = { 342, 345, 347 };
case_special_t unigen_special_0x1f94 = { 349, 352, 354 };
case_special_t unigen_special_0x1f95 = { 356, 359, 361 };
case_special_t unigen_special_0x1f96 = { 363, 366, 368 };
case_special_t unigen_special_0x1f97 = { 370, 373, 375 };
case_special_t unigen_special_0x1f98 = { 377, 380, 382 };
case_special_t unigen_special_0x1f99 = { 384, 387, 389 };
case_special_t unigen_special_0x1f9a = { 391, 394, 396 };
case_special_t unigen_special_0x1f9b = { 398, 401, 403 };
case_special_t unigen_special_0x1f9c = { 405, 408, 410 };
case_special_t unigen_special_0x1f9d = { 412, 415, 417 };
case_special_t unigen_special_0x1f9e = { 419, 422, 424 };
case_special_t unigen_special_0x1f9f = { 426, 429, 431 };
case_special_t unigen_special_0x1fa0 = { 433, 436, 438 };
case_special_t unigen_special_0x1fa1 = { 440, 443, 445 };
case_special_t unigen_special_0x1fa2 = { 447, 450, 452 };
case_special_t unigen_special_0x1fa3 = { 454, 457, 459 };
case_special_t unigen_special_0x1fa4 = { 461, 464, 466 };
case_special_t unigen_special_0x1fa5 = { 468, 471, 473 };
case_special_t unigen_special_0x1fa6 = { 475, 478, 480 };
case_special_t unigen_special_0x1fa7 = { 482, 485, 487 };
case_special_t unigen_special_0x1fa8 = { 489, 492, 494 };
case_special_t unigen_special_0x1fa9 = { 496, 499, 501 };
case_special_t unigen_special_0x1faa = { 503, 506, 508 };
case_special_t unigen_special_0x1fab = { 510, 513, 515 };
case_special_t unigen_special_0x1fac = { 517, 520, 522 };
case_special_t unigen_special_0x1fad = { 524, 527, 529 };
case_special_t unigen_special_0x1fae = { 531, 534, 536 };
case_special_t unigen_special_0x1faf = { 538, 541, 543 };
case_special_t unigen_special_0x1fb2 = { 545, 548, 550 };
case_special_t unigen_special_0x1fb3 = { 553, 556, 558 };
case_special_t unigen_special_0x1fb4 = { 560, 563, 565 };
case_special_t unigen_special_0x1fb6 = { 568, 571, 573 };
case_special_t unigen_special_0x1fb7 = { 576, 580, 582 };
case_special_t unigen_special_0x1fbc = { 586, 589, 591 };
case_special_t unigen_special_0x1fc2 = { 593, 596, 598 };
case_special_t unigen_special_0x1fc3 = { 601, 604, 606 };
case_special_t unigen_special_0x1fc4 = { 608, 611, 613 };
case_special_t unigen_special_0x1fc6 = { 616, 619, 621 };
case_special_t unigen_special_0x1fc7 = { 624, 628, 630 };
case_special_t unigen_special_0x1fcc = { 634, 637, 639 };
case_special_t unigen_special_0x1fd2 = { 641, 645, 647 };
case_special_t unigen_special_0x1fd3 = { 651, 655, 657 };
case_special_t unigen_special_0x1fd6 = { 661, 664, 666 };
case_special_t unigen_special_0x1fd7 = { 669, 673, 675 };
case_special_t unigen_special_0x1fe2 = { 679, 683, 685 };
case_special_t unigen_special_0x1fe3 = { 689, 693, 695 };
case_special_t unigen_special_0x1fe4 = { 699, 702, 704 };
case_special_t unigen_special_0x1fe6 = { 707, 710, 712 };
case_special_t unigen_special_0x1fe7 = { 715, 719, 721 };
case_special_t unigen_special_0x1ff2 = { 725, 728, 730 };
case_special_t unigen_special_0x1ff3 = { 733, 736, 738 };
case_special_t unigen_special_0x1ff4 = { 740, 743, 745 };
case_special_t unigen_special_0x1ff6 = { 748, 751, 753 };
case_special_t unigen_special_0x1ff7 = { 756, 760, 762 };
case_special_t unigen_special_0x1ffc = { 766, 769, 771 };
case_special_t unigen_special_0xfb00 = { 773, 776, 778 };
case_special_t unigen_special_0xfb01 = { 781, 784, 786 };
case_special_t unigen_special_0xfb02 = { 789, 792, 794 };
case_special_t unigen_special_0xfb03 = { 797, 801, 803 };
case_special_t unigen_special_0xfb04 = { 807, 811, 813 };
case_special_t unigen_special_0xfb05 = { 817, 820, 822 };
case_special_t unigen_special_0xfb06 = { 825, 828, 830 };
case_special_t unigen_special_0xfb13 = { 833, 836, 838 };
case_special_t unigen_special_0xfb14 = { 841, 844, 846 };
case_special_t unigen_special_0xfb15 = { 849, 852, 854 };
case_special_t unigen_special_0xfb16 = { 857, 860, 862 };
case_special_t unigen_special_0xfb17 = { 865, 868, 870 };

static void get_case_special(glui32 ch, glui32 **specptr)
{
  switch (ch)
  {
  case 0xdf:
    *specptr = unigen_special_0xdf;
    break;
  case 0x130:
    *specptr = unigen_special_0x130;
    break;
  case 0x149:
    *specptr = unigen_special_0x149;
    break;
  case 0x1c4:
    *specptr = unigen_special_0x1c4;
    break;
  case 0x1c5:
    *specptr = unigen_special_0x1c5;
    break;
  case 0x1c6:
    *specptr = unigen_special_0x1c6;
    break;
  case 0x1c7:
    *specptr = unigen_special_0x1c7;
    break;
  case 0x1c8:
    *specptr = unigen_special_0x1c8;
    break;
  case 0x1c9:
    *specptr = unigen_special_0x1c9;
    break;
  case 0x1ca:
    *specptr = unigen_special_0x1ca;
    break;
  case 0x1cb:
    *specptr = unigen_special_0x1cb;
    break;
  case 0x1cc:
    *specptr = unigen_special_0x1cc;
    break;
  case 0x1f0:
    *specptr = unigen_special_0x1f0;
    break;
  case 0x1f1:
    *specptr = unigen_special_0x1f1;
    break;
  case 0x1f2:
    *specptr = unigen_special_0x1f2;
    break;
  case 0x1f3:
    *specptr = unigen_special_0x1f3;
    break;
  case 0x390:
    *specptr = unigen_special_0x390;
    break;
  case 0x3b0:
    *specptr = unigen_special_0x3b0;
    break;
  case 0x587:
    *specptr = unigen_special_0x587;
    break;
  case 0x1e96:
    *specptr = unigen_special_0x1e96;
    break;
  case 0x1e97:
    *specptr = unigen_special_0x1e97;
    break;
  case 0x1e98:
    *specptr = unigen_special_0x1e98;
    break;
  case 0x1e99:
    *specptr = unigen_special_0x1e99;
    break;
  case 0x1e9a:
    *specptr = unigen_special_0x1e9a;
    break;
  case 0x1f50:
    *specptr = unigen_special_0x1f50;
    break;
  case 0x1f52:
    *specptr = unigen_special_0x1f52;
    break;
  case 0x1f54:
    *specptr = unigen_special_0x1f54;
    break;
  case 0x1f56:
    *specptr = unigen_special_0x1f56;
    break;
  case 0x1f80:
    *specptr = unigen_special_0x1f80;
    break;
  case 0x1f81:
    *specptr = unigen_special_0x1f81;
    break;
  case 0x1f82:
    *specptr = unigen_special_0x1f82;
    break;
  case 0x1f83:
    *specptr = unigen_special_0x1f83;
    break;
  case 0x1f84:
    *specptr = unigen_special_0x1f84;
    break;
  case 0x1f85:
    *specptr = unigen_special_0x1f85;
    break;
  case 0x1f86:
    *specptr = unigen_special_0x1f86;
    break;
  case 0x1f87:
    *specptr = unigen_special_0x1f87;
    break;
  case 0x1f88:
    *specptr = unigen_special_0x1f88;
    break;
  case 0x1f89:
    *specptr = unigen_special_0x1f89;
    break;
  case 0x1f8a:
    *specptr = unigen_special_0x1f8a;
    break;
  case 0x1f8b:
    *specptr = unigen_special_0x1f8b;
    break;
  case 0x1f8c:
    *specptr = unigen_special_0x1f8c;
    break;
  case 0x1f8d:
    *specptr = unigen_special_0x1f8d;
    break;
  case 0x1f8e:
    *specptr = unigen_special_0x1f8e;
    break;
  case 0x1f8f:
    *specptr = unigen_special_0x1f8f;
    break;
  case 0x1f90:
    *specptr = unigen_special_0x1f90;
    break;
  case 0x1f91:
    *specptr = unigen_special_0x1f91;
    break;
  case 0x1f92:
    *specptr = unigen_special_0x1f92;
    break;
  case 0x1f93:
    *specptr = unigen_special_0x1f93;
    break;
  case 0x1f94:
    *specptr = unigen_special_0x1f94;
    break;
  case 0x1f95:
    *specptr = unigen_special_0x1f95;
    break;
  case 0x1f96:
    *specptr = unigen_special_0x1f96;
    break;
  case 0x1f97:
    *specptr = unigen_special_0x1f97;
    break;
  case 0x1f98:
    *specptr = unigen_special_0x1f98;
    break;
  case 0x1f99:
    *specptr = unigen_special_0x1f99;
    break;
  case 0x1f9a:
    *specptr = unigen_special_0x1f9a;
    break;
  case 0x1f9b:
    *specptr = unigen_special_0x1f9b;
    break;
  case 0x1f9c:
    *specptr = unigen_special_0x1f9c;
    break;
  case 0x1f9d:
    *specptr = unigen_special_0x1f9d;
    break;
  case 0x1f9e:
    *specptr = unigen_special_0x1f9e;
    break;
  case 0x1f9f:
    *specptr = unigen_special_0x1f9f;
    break;
  case 0x1fa0:
    *specptr = unigen_special_0x1fa0;
    break;
  case 0x1fa1:
    *specptr = unigen_special_0x1fa1;
    break;
  case 0x1fa2:
    *specptr = unigen_special_0x1fa2;
    break;
  case 0x1fa3:
    *specptr = unigen_special_0x1fa3;
    break;
  case 0x1fa4:
    *specptr = unigen_special_0x1fa4;
    break;
  case 0x1fa5:
    *specptr = unigen_special_0x1fa5;
    break;
  case 0x1fa6:
    *specptr = unigen_special_0x1fa6;
    break;
  case 0x1fa7:
    *specptr = unigen_special_0x1fa7;
    break;
  case 0x1fa8:
    *specptr = unigen_special_0x1fa8;
    break;
  case 0x1fa9:
    *specptr = unigen_special_0x1fa9;
    break;
  case 0x1faa:
    *specptr = unigen_special_0x1faa;
    break;
  case 0x1fab:
    *specptr = unigen_special_0x1fab;
    break;
  case 0x1fac:
    *specptr = unigen_special_0x1fac;
    break;
  case 0x1fad:
    *specptr = unigen_special_0x1fad;
    break;
  case 0x1fae:
    *specptr = unigen_special_0x1fae;
    break;
  case 0x1faf:
    *specptr = unigen_special_0x1faf;
    break;
  case 0x1fb2:
    *specptr = unigen_special_0x1fb2;
    break;
  case 0x1fb3:
    *specptr = unigen_special_0x1fb3;
    break;
  case 0x1fb4:
    *specptr = unigen_special_0x1fb4;
    break;
  case 0x1fb6:
    *specptr = unigen_special_0x1fb6;
    break;
  case 0x1fb7:
    *specptr = unigen_special_0x1fb7;
    break;
  case 0x1fbc:
    *specptr = unigen_special_0x1fbc;
    break;
  case 0x1fc2:
    *specptr = unigen_special_0x1fc2;
    break;
  case 0x1fc3:
    *specptr = unigen_special_0x1fc3;
    break;
  case 0x1fc4:
    *specptr = unigen_special_0x1fc4;
    break;
  case 0x1fc6:
    *specptr = unigen_special_0x1fc6;
    break;
  case 0x1fc7:
    *specptr = unigen_special_0x1fc7;
    break;
  case 0x1fcc:
    *specptr = unigen_special_0x1fcc;
    break;
  case 0x1fd2:
    *specptr = unigen_special_0x1fd2;
    break;
  case 0x1fd3:
    *specptr = unigen_special_0x1fd3;
    break;
  case 0x1fd6:
    *specptr = unigen_special_0x1fd6;
    break;
  case 0x1fd7:
    *specptr = unigen_special_0x1fd7;
    break;
  case 0x1fe2:
    *specptr = unigen_special_0x1fe2;
    break;
  case 0x1fe3:
    *specptr = unigen_special_0x1fe3;
    break;
  case 0x1fe4:
    *specptr = unigen_special_0x1fe4;
    break;
  case 0x1fe6:
    *specptr = unigen_special_0x1fe6;
    break;
  case 0x1fe7:
    *specptr = unigen_special_0x1fe7;
    break;
  case 0x1ff2:
    *specptr = unigen_special_0x1ff2;
    break;
  case 0x1ff3:
    *specptr = unigen_special_0x1ff3;
    break;
  case 0x1ff4:
    *specptr = unigen_special_0x1ff4;
    break;
  case 0x1ff6:
    *specptr = unigen_special_0x1ff6;
    break;
  case 0x1ff7:
    *specptr = unigen_special_0x1ff7;
    break;
  case 0x1ffc:
    *specptr = unigen_special_0x1ffc;
    break;
  case 0xfb00:
    *specptr = unigen_special_0xfb00;
    break;
  case 0xfb01:
    *specptr = unigen_special_0xfb01;
    break;
  case 0xfb02:
    *specptr = unigen_special_0xfb02;
    break;
  case 0xfb03:
    *specptr = unigen_special_0xfb03;
    break;
  case 0xfb04:
    *specptr = unigen_special_0xfb04;
    break;
  case 0xfb05:
    *specptr = unigen_special_0xfb05;
    break;
  case 0xfb06:
    *specptr = unigen_special_0xfb06;
    break;
  case 0xfb13:
    *specptr = unigen_special_0xfb13;
    break;
  case 0xfb14:
    *specptr = unigen_special_0xfb14;
    break;
  case 0xfb15:
    *specptr = unigen_special_0xfb15;
    break;
  case 0xfb16:
    *specptr = unigen_special_0xfb16;
    break;
  case 0xfb17:
    *specptr = unigen_special_0xfb17;
    break;
  default:
    *specptr = NULL;
    break;
  }
}

glui32 buffer_change_case(glui32 *buf, glui32 len,
  glui32 numchars, int destcase, int cond, int changerest)
{
  glui32 ix, jx;
  glui32 *outbuf;
  glui32 *newoutbuf;
  glui32 outcount;
  int dest_block_rest = 0, dest_block_first = 0;
  int dest_spec_rest = 0, dest_spec_first = 0;

  switch (cond)
  {
  case COND_ALL:
    dest_spec_rest = destcase;
    dest_spec_first = destcase;
    break;
  case COND_LINESTART:
    if (changerest)
      dest_spec_rest = CASE_LOWER;
    else
      dest_spec_rest = CASE_IDENT;
    dest_spec_first = destcase;
    break;
  }

  dest_block_rest = dest_spec_rest;
  if (dest_block_rest == CASE_TITLE)
    dest_block_rest = CASE_UPPER;
  dest_block_first = dest_spec_first;
  if (dest_block_first == CASE_TITLE)
    dest_block_first = CASE_UPPER;

  newoutbuf = NULL;
  outcount = 0;
  outbuf = buf;

  for (ix = 0; ix < numchars; ix++)
  {
    int target;
    int isfirst;
    glui32 res;
    glui32 *special;
    glui32 *ptr;
    glui32 speccount;
    glui32 ch = buf[ix];

    isfirst = (ix == 0);

    target = (isfirst ? dest_block_first : dest_block_rest);
    if (target == CASE_IDENT)
      res = ch;
    else
    {
      case_block_t *block;

      get_case_block(ch, &block);
      if (!block)
        res = ch;
      else
        res = block[ch & 0xFF][target];
    }

    if (res != 0xFFFFFFFF || res == ch)
    {
      if (outcount < len)
        outbuf[outcount] = res;
      outcount++;
      continue;
    }

    target = (isfirst ? dest_spec_first : dest_spec_rest);

    get_case_special(ch, &special);
    if (!special)
      continue;

    ptr = &unigen_special_array[special[target]];
    speccount = *(ptr++);

    if (speccount == 1)
    {
      if (outcount < len)
        outbuf[outcount] = ptr[0];
      outcount++;
      continue;
    }

    if (!newoutbuf)
    {
      newoutbuf = (glui32*)malloc((len+1) * sizeof(glui32));
      if (!newoutbuf)
        return 0;
      if (outcount)
        memcpy(newoutbuf, buf, outcount * sizeof(glui32));
      outbuf = newoutbuf;
    }

    for (jx = 0; jx < speccount; jx++)
    {
      if (outcount < len)
        outbuf[outcount] = ptr[jx];
      outcount++;
    }
  }

  if (newoutbuf)
  {
    glui32 copycount = (outcount > len) ? len : outcount;
    if (copycount)
      memcpy(buf, newoutbuf, copycount * sizeof(glui32));
    free(newoutbuf);
  }

  return outcount;
}

static glui32 combining_class(glui32 ch)
{
  switch (ch >> 8)
  {
    case 3:
      switch (ch)
      {
        case 820:
        case 821:
        case 822:
        case 823:
        case 824:
          return 1;
        case 801:
        case 802:
        case 807:
        case 808:
          return 202;
        case 795:
          return 216;
        case 790:
        case 791:
        case 792:
        case 793:
        case 796:
        case 797:
        case 798:
        case 799:
        case 800:
        case 803:
        case 804:
        case 805:
        case 806:
        case 809:
        case 810:
        case 811:
        case 812:
        case 813:
        case 814:
        case 815:
        case 816:
        case 817:
        case 818:
        case 819:
        case 825:
        case 826:
        case 827:
        case 828:
        case 839:
        case 840:
        case 841:
        case 845:
        case 846:
        case 851:
        case 852:
        case 853:
        case 854:
          return 220;
        case 768:
        case 769:
        case 770:
        case 771:
        case 772:
        case 773:
        case 774:
        case 775:
        case 776:
        case 777:
        case 778:
        case 779:
        case 780:
        case 781:
        case 782:
        case 783:
        case 784:
        case 785:
        case 786:
        case 787:
        case 788:
        case 829:
        case 830:
        case 831:
        case 832:
        case 833:
        case 834:
        case 835:
        case 836:
        case 838:
        case 842:
        case 843:
        case 844:
        case 848:
        case 849:
        case 850:
        case 855:
        case 867:
        case 868:
        case 869:
        case 870:
        case 871:
        case 872:
        case 873:
        case 874:
        case 875:
        case 876:
        case 877:
        case 878:
        case 879:
          return 230;
        case 789:
        case 794:
          return 232;
        case 863:
        case 866:
          return 233;
        case 861:
        case 862:
        case 864:
        case 865:
          return 234;
        case 837:
          return 240;
      }
      return 0;
    case 4:
      switch (ch)
      {
        case 1155:
        case 1156:
        case 1157:
        case 1158:
          return 230;
      }
      return 0;
    case 5:
      switch (ch)
      {
        case 1456:
          return 10;
        case 1457:
          return 11;
        case 1458:
          return 12;
        case 1459:
          return 13;
        case 1460:
          return 14;
        case 1461:
          return 15;
        case 1462:
          return 16;
        case 1463:
          return 17;
        case 1464:
          return 18;
        case 1465:
          return 19;
        case 1467:
          return 20;
        case 1468:
          return 21;
        case 1469:
          return 22;
        case 1471:
          return 23;
        case 1473:
          return 24;
        case 1474:
          return 25;
        case 1425:
        case 1430:
        case 1435:
        case 1443:
        case 1444:
        case 1445:
        case 1446:
        case 1447:
        case 1450:
          return 220;
        case 1434:
        case 1453:
          return 222;
        case 1454:
          return 228;
        case 1426:
        case 1427:
        case 1428:
        case 1429:
        case 1431:
        case 1432:
        case 1433:
        case 1436:
        case 1437:
        case 1438:
        case 1439:
        case 1440:
        case 1441:
        case 1448:
        case 1449:
        case 1451:
        case 1452:
        case 1455:
        case 1476:
          return 230;
      }
      return 0;
    case 6:
      switch (ch)
      {
        case 1611:
          return 27;
        case 1612:
          return 28;
        case 1613:
          return 29;
        case 1614:
          return 30;
        case 1615:
          return 31;
        case 1616:
          return 32;
        case 1617:
          return 33;
        case 1618:
          return 34;
        case 1648:
          return 35;
        case 1621:
        case 1622:
        case 1763:
        case 1770:
        case 1773:
          return 220;
        case 1552:
        case 1553:
        case 1554:
        case 1555:
        case 1556:
        case 1557:
        case 1619:
        case 1620:
        case 1623:
        case 1624:
        case 1750:
        case 1751:
        case 1752:
        case 1753:
        case 1754:
        case 1755:
        case 1756:
        case 1759:
        case 1760:
        case 1761:
        case 1762:
        case 1764:
        case 1767:
        case 1768:
        case 1771:
        case 1772:
          return 230;
      }
      return 0;
    case 7:
      switch (ch)
      {
        case 1809:
          return 36;
        case 1841:
        case 1844:
        case 1847:
        case 1848:
        case 1849:
        case 1851:
        case 1852:
        case 1854:
        case 1858:
        case 1860:
        case 1862:
        case 1864:
          return 220;
        case 1840:
        case 1842:
        case 1843:
        case 1845:
        case 1846:
        case 1850:
        case 1853:
        case 1855:
        case 1856:
        case 1857:
        case 1859:
        case 1861:
        case 1863:
        case 1865:
        case 1866:
          return 230;
      }
      return 0;
    case 9:
      switch (ch)
      {
        case 2364:
        case 2492:
          return 7;
        case 2381:
        case 2509:
          return 9;
        case 2386:
          return 220;
        case 2385:
        case 2387:
        case 2388:
          return 230;
      }
      return 0;
    case 10:
      switch (ch)
      {
        case 2620:
        case 2748:
          return 7;
        case 2637:
        case 2765:
          return 9;
      }
      return 0;
    case 11:
      switch (ch)
      {
        case 2876:
          return 7;
        case 2893:
        case 3021:
          return 9;
      }
      return 0;
    case 12:
      switch (ch)
      {
        case 3260:
          return 7;
        case 3149:
        case 3277:
          return 9;
        case 3157:
          return 84;
        case 3158:
          return 91;
      }
      return 0;
    case 13:
      switch (ch)
      {
        case 3405:
        case 3530:
          return 9;
      }
      return 0;
    case 14:
      switch (ch)
      {
        case 3642:
          return 9;
        case 3640:
        case 3641:
          return 103;
        case 3656:
        case 3657:
        case 3658:
        case 3659:
          return 107;
        case 3768:
        case 3769:
          return 118;
        case 3784:
        case 3785:
        case 3786:
        case 3787:
          return 122;
      }
      return 0;
    case 15:
      switch (ch)
      {
        case 3972:
          return 9;
        case 3953:
          return 129;
        case 3954:
        case 3962:
        case 3963:
        case 3964:
        case 3965:
        case 3968:
          return 130;
        case 3956:
          return 132;
        case 3897:
          return 216;
        case 3864:
        case 3865:
        case 3893:
        case 3895:
        case 4038:
          return 220;
        case 3970:
        case 3971:
        case 3974:
        case 3975:
          return 230;
      }
      return 0;
    case 16:
      switch (ch)
      {
        case 4151:
          return 7;
        case 4153:
          return 9;
      }
      return 0;
    case 23:
      switch (ch)
      {
        case 5908:
        case 5940:
        case 6098:
          return 9;
        case 6109:
          return 230;
      }
      return 0;
    case 24:
      switch (ch)
      {
        case 6313:
          return 228;
      }
      return 0;
    case 25:
      switch (ch)
      {
        case 6459:
          return 220;
        case 6457:
          return 222;
        case 6458:
          return 230;
      }
      return 0;
    case 32:
      switch (ch)
      {
        case 8402:
        case 8403:
        case 8408:
        case 8409:
        case 8410:
        case 8421:
        case 8422:
        case 8426:
          return 1;
        case 8424:
          return 220;
        case 8400:
        case 8401:
        case 8404:
        case 8405:
        case 8406:
        case 8407:
        case 8411:
        case 8412:
        case 8417:
        case 8423:
        case 8425:
          return 230;
      }
      return 0;
    case 48:
      switch (ch)
      {
        case 12441:
        case 12442:
          return 8;
        case 12330:
          return 218;
        case 12333:
          return 222;
        case 12334:
        case 12335:
          return 224;
        case 12331:
          return 228;
        case 12332:
          return 232;
      }
      return 0;
    case 251:
      switch (ch)
      {
        case 64286:
          return 26;
      }
      return 0;
    case 254:
      switch (ch)
      {
        case 65056:
        case 65057:
        case 65058:
        case 65059:
          return 230;
      }
      return 0;
    case 465:
      switch (ch)
      {
        case 119143:
        case 119144:
        case 119145:
          return 1;
        case 119141:
        case 119142:
        case 119150:
        case 119151:
        case 119152:
        case 119153:
        case 119154:
          return 216;
        case 119163:
        case 119164:
        case 119165:
        case 119166:
        case 119167:
        case 119168:
        case 119169:
        case 119170:
        case 119178:
        case 119179:
          return 220;
        case 119149:
          return 226;
        case 119173:
        case 119174:
        case 119175:
        case 119176:
        case 119177:
        case 119210:
        case 119211:
        case 119212:
        case 119213:
          return 230;
      }
      return 0;
  }
  return 0;
}

static glui32 unigen_decomp_data[3247] = {
  0x41, 0x300, 0x41, 0x301, 0x41, 0x302, 0x41, 0x303,
  0x41, 0x308, 0x41, 0x30a, 0x43, 0x327, 0x45, 0x300,
  0x45, 0x301, 0x45, 0x302, 0x45, 0x308, 0x49, 0x300,
  0x49, 0x301, 0x49, 0x302, 0x49, 0x308, 0x4e, 0x303,
  0x4f, 0x300, 0x4f, 0x301, 0x4f, 0x302, 0x4f, 0x303,
  0x4f, 0x308, 0x55, 0x300, 0x55, 0x301, 0x55, 0x302,
  0x55, 0x308, 0x59, 0x301, 0x61, 0x300, 0x61, 0x301,
  0x61, 0x302, 0x61, 0x303, 0x61, 0x308, 0x61, 0x30a,
  0x63, 0x327, 0x65, 0x300, 0x65, 0x301, 0x65, 0x302,
  0x65, 0x308, 0x69, 0x300, 0x69, 0x301, 0x69, 0x302,
  0x69, 0x308, 0x6e, 0x303, 0x6f, 0x300, 0x6f, 0x301,
  0x6f, 0x302, 0x6f, 0x303, 0x6f, 0x308, 0x75, 0x300,
  0x75, 0x301, 0x75, 0x302, 0x75, 0x308, 0x79, 0x301,
  0x79, 0x308, 0x41, 0x304, 0x61, 0x304, 0x41, 0x306,
  0x61, 0x306, 0x41, 0x328, 0x61, 0x328, 0x43, 0x301,
  0x63, 0x301, 0x43, 0x302, 0x63, 0x302, 0x43, 0x307,
  0x63, 0x307, 0x43, 0x30c, 0x63, 0x30c, 0x44, 0x30c,
  0x64, 0x30c, 0x45, 0x304, 0x65, 0x304, 0x45, 0x306,
  0x65, 0x306, 0x45, 0x307, 0x65, 0x307, 0x45, 0x328,
  0x65, 0x328, 0x45, 0x30c, 0x65, 0x30c, 0x47, 0x302,
  0x67, 0x302, 0x47, 0x306, 0x67, 0x306, 0x47, 0x307,
  0x67, 0x307, 0x47, 0x327, 0x67, 0x327, 0x48, 0x302,
  0x68, 0x302, 0x49, 0x303, 0x69, 0x303, 0x49, 0x304,
  0x69, 0x304, 0x49, 0x306, 0x69, 0x306, 0x49, 0x328,
  0x69, 0x328, 0x49, 0x307, 0x4a, 0x302, 0x6a, 0x302,
  0x4b, 0x327, 0x6b, 0x327, 0x4c, 0x301, 0x6c, 0x301,
  0x4c, 0x327, 0x6c, 0x327, 0x4c, 0x30c, 0x6c, 0x30c,
  0x4e, 0x301, 0x6e, 0x301, 0x4e, 0x327, 0x6e, 0x327,
  0x4e, 0x30c, 0x6e, 0x30c, 0x4f, 0x304, 0x6f, 0x304,
  0x4f, 0x306, 0x6f, 0x306, 0x4f, 0x30b, 0x6f, 0x30b,
  0x52, 0x301, 0x72, 0x301, 0x52, 0x327, 0x72, 0x327,
  0x52, 0x30c, 0x72, 0x30c, 0x53, 0x301, 0x73, 0x301,
  0x53, 0x302, 0x73, 0x302, 0x53, 0x327, 0x73, 0x327,
  0x53, 0x30c, 0x73, 0x30c, 0x54, 0x327, 0x74, 0x327,
  0x54, 0x30c, 0x74, 0x30c, 0x55, 0x303, 0x75, 0x303,
  0x55, 0x304, 0x75, 0x304, 0x55, 0x306, 0x75, 0x306,
  0x55, 0x30a, 0x75, 0x30a, 0x55, 0x30b, 0x75, 0x30b,
  0x55, 0x328, 0x75, 0x328, 0x57, 0x302, 0x77, 0x302,
  0x59, 0x302, 0x79, 0x302, 0x59, 0x308, 0x5a, 0x301,
  0x7a, 0x301, 0x5a, 0x307, 0x7a, 0x307, 0x5a, 0x30c,
  0x7a, 0x30c, 0x4f, 0x31b, 0x6f, 0x31b, 0x55, 0x31b,
  0x75, 0x31b, 0x41, 0x30c, 0x61, 0x30c, 0x49, 0x30c,
  0x69, 0x30c, 0x4f, 0x30c, 0x6f, 0x30c, 0x55, 0x30c,
  0x75, 0x30c, 0x55, 0x308, 0x304, 0x75, 0x308, 0x304,
  0x55, 0x308, 0x301, 0x75, 0x308, 0x301, 0x55, 0x308,
  0x30c, 0x75, 0x308, 0x30c, 0x55, 0x308, 0x300, 0x75,
  0x308, 0x300, 0x41, 0x308, 0x304, 0x61, 0x308, 0x304,
  0x41, 0x307, 0x304, 0x61, 0x307, 0x304, 0xc6, 0x304,
  0xe6, 0x304, 0x47, 0x30c, 0x67, 0x30c, 0x4b, 0x30c,
  0x6b, 0x30c, 0x4f, 0x328, 0x6f, 0x328, 0x4f, 0x328,
  0x304, 0x6f, 0x328, 0x304, 0x1b7, 0x30c, 0x292, 0x30c,
  0x6a, 0x30c, 0x47, 0x301, 0x67, 0x301, 0x4e, 0x300,
  0x6e, 0x300, 0x41, 0x30a, 0x301, 0x61, 0x30a, 0x301,
  0xc6, 0x301, 0xe6, 0x301, 0xd8, 0x301, 0xf8, 0x301,
  0x41, 0x30f, 0x61, 0x30f, 0x41, 0x311, 0x61, 0x311,
  0x45, 0x30f, 0x65, 0x30f, 0x45, 0x311, 0x65, 0x311,
  0x49, 0x30f, 0x69, 0x30f, 0x49, 0x311, 0x69, 0x311,
  0x4f, 0x30f, 0x6f, 0x30f, 0x4f, 0x311, 0x6f, 0x311,
  0x52, 0x30f, 0x72, 0x30f, 0x52, 0x311, 0x72, 0x311,
  0x55, 0x30f, 0x75, 0x30f, 0x55, 0x311, 0x75, 0x311,
  0x53, 0x326, 0x73, 0x326, 0x54, 0x326, 0x74, 0x326,
  0x48, 0x30c, 0x68, 0x30c, 0x41, 0x307, 0x61, 0x307,
  0x45, 0x327, 0x65, 0x327, 0x4f, 0x308, 0x304, 0x6f,
  0x308, 0x304, 0x4f, 0x303, 0x304, 0x6f, 0x303, 0x304,
  0x4f, 0x307, 0x6f, 0x307, 0x4f, 0x307, 0x304, 0x6f,
  0x307, 0x304, 0x59, 0x304, 0x79, 0x304, 0x300, 0x301,
  0x313, 0x308, 0x301, 0x2b9, 0x3b, 0xa8, 0x301, 0x391,
  0x301, 0xb7, 0x395, 0x301, 0x397, 0x301, 0x399, 0x301,
  0x39f, 0x301, 0x3a5, 0x301, 0x3a9, 0x301, 0x3b9, 0x308,
  0x301, 0x399, 0x308, 0x3a5, 0x308, 0x3b1, 0x301, 0x3b5,
  0x301, 0x3b7, 0x301, 0x3b9, 0x301, 0x3c5, 0x308, 0x301,
  0x3b9, 0x308, 0x3c5, 0x308, 0x3bf, 0x301, 0x3c5, 0x301,
  0x3c9, 0x301, 0x3d2, 0x301, 0x3d2, 0x308, 0x415, 0x300,
  0x415, 0x308, 0x413, 0x301, 0x406, 0x308, 0x41a, 0x301,
  0x418, 0x300, 0x423, 0x306, 0x418, 0x306, 0x438, 0x306,
  0x435, 0x300, 0x435, 0x308, 0x433, 0x301, 0x456, 0x308,
  0x43a, 0x301, 0x438, 0x300, 0x443, 0x306, 0x474, 0x30f,
  0x475, 0x30f, 0x416, 0x306, 0x436, 0x306, 0x410, 0x306,
  0x430, 0x306, 0x410, 0x308, 0x430, 0x308, 0x415, 0x306,
  0x435, 0x306, 0x4d8, 0x308, 0x4d9, 0x308, 0x416, 0x308,
  0x436, 0x308, 0x417, 0x308, 0x437, 0x308, 0x418, 0x304,
  0x438, 0x304, 0x418, 0x308, 0x438, 0x308, 0x41e, 0x308,
  0x43e, 0x308, 0x4e8, 0x308, 0x4e9, 0x308, 0x42d, 0x308,
  0x44d, 0x308, 0x423, 0x304, 0x443, 0x304, 0x423, 0x308,
  0x443, 0x308, 0x423, 0x30b, 0x443, 0x30b, 0x427, 0x308,
  0x447, 0x308, 0x42b, 0x308, 0x44b, 0x308, 0x627, 0x653,
  0x627, 0x654, 0x648, 0x654, 0x627, 0x655, 0x64a, 0x654,
  0x6d5, 0x654, 0x6c1, 0x654, 0x6d2, 0x654, 0x928, 0x93c,
  0x930, 0x93c, 0x933, 0x93c, 0x915, 0x93c, 0x916, 0x93c,
  0x917, 0x93c, 0x91c, 0x93c, 0x921, 0x93c, 0x922, 0x93c,
  0x92b, 0x93c, 0x92f, 0x93c, 0x9c7, 0x9be, 0x9c7, 0x9d7,
  0x9a1, 0x9bc, 0x9a2, 0x9bc, 0x9af, 0x9bc, 0xa32, 0xa3c,
  0xa38, 0xa3c, 0xa16, 0xa3c, 0xa17, 0xa3c, 0xa1c, 0xa3c,
  0xa2b, 0xa3c, 0xb47, 0xb56, 0xb47, 0xb3e, 0xb47, 0xb57,
  0xb21, 0xb3c, 0xb22, 0xb3c, 0xb92, 0xbd7, 0xbc6, 0xbbe,
  0xbc7, 0xbbe, 0xbc6, 0xbd7, 0xc46, 0xc56, 0xcbf, 0xcd5,
  0xcc6, 0xcd5, 0xcc6, 0xcd6, 0xcc6, 0xcc2, 0xcc6, 0xcc2,
  0xcd5, 0xd46, 0xd3e, 0xd47, 0xd3e, 0xd46, 0xd57, 0xdd9,
  0xdca, 0xdd9, 0xdcf, 0xdd9, 0xdcf, 0xdca, 0xdd9, 0xddf,
  0xf42, 0xfb7, 0xf4c, 0xfb7, 0xf51, 0xfb7, 0xf56, 0xfb7,
  0xf5b, 0xfb7, 0xf40, 0xfb5, 0xf71, 0xf72, 0xf71, 0xf74,
  0xfb2, 0xf80, 0xfb3, 0xf80, 0xf71, 0xf80, 0xf92, 0xfb7,
  0xf9c, 0xfb7, 0xfa1, 0xfb7, 0xfa6, 0xfb7, 0xfab, 0xfb7,
  0xf90, 0xfb5, 0x1025, 0x102e, 0x41, 0x325, 0x61, 0x325,
  0x42, 0x307, 0x62, 0x307, 0x42, 0x323, 0x62, 0x323,
  0x42, 0x331, 0x62, 0x331, 0x43, 0x327, 0x301, 0x63,
  0x327, 0x301, 0x44, 0x307, 0x64, 0x307, 0x44, 0x323,
  0x64, 0x323, 0x44, 0x331, 0x64, 0x331, 0x44, 0x327,
  0x64, 0x327, 0x44, 0x32d, 0x64, 0x32d, 0x45, 0x304,
  0x300, 0x65, 0x304, 0x300, 0x45, 0x304, 0x301, 0x65,
  0x304, 0x301, 0x45, 0x32d, 0x65, 0x32d, 0x45, 0x330,
  0x65, 0x330, 0x45, 0x327, 0x306, 0x65, 0x327, 0x306,
  0x46, 0x307, 0x66, 0x307, 0x47, 0x304, 0x67, 0x304,
  0x48, 0x307, 0x68, 0x307, 0x48, 0x323, 0x68, 0x323,
  0x48, 0x308, 0x68, 0x308, 0x48, 0x327, 0x68, 0x327,
  0x48, 0x32e, 0x68, 0x32e, 0x49, 0x330, 0x69, 0x330,
  0x49, 0x308, 0x301, 0x69, 0x308, 0x301, 0x4b, 0x301,
  0x6b, 0x301, 0x4b, 0x323, 0x6b, 0x323, 0x4b, 0x331,
  0x6b, 0x331, 0x4c, 0x323, 0x6c, 0x323, 0x4c, 0x323,
  0x304, 0x6c, 0x323, 0x304, 0x4c, 0x331, 0x6c, 0x331,
  0x4c, 0x32d, 0x6c, 0x32d, 0x4d, 0x301, 0x6d, 0x301,
  0x4d, 0x307, 0x6d, 0x307, 0x4d, 0x323, 0x6d, 0x323,
  0x4e, 0x307, 0x6e, 0x307, 0x4e, 0x323, 0x6e, 0x323,
  0x4e, 0x331, 0x6e, 0x331, 0x4e, 0x32d, 0x6e, 0x32d,
  0x4f, 0x303, 0x301, 0x6f, 0x303, 0x301, 0x4f, 0x303,
  0x308, 0x6f, 0x303, 0x308, 0x4f, 0x304, 0x300, 0x6f,
  0x304, 0x300, 0x4f, 0x304, 0x301, 0x6f, 0x304, 0x301,
  0x50, 0x301, 0x70, 0x301, 0x50, 0x307, 0x70, 0x307,
  0x52, 0x307, 0x72, 0x307, 0x52, 0x323, 0x72, 0x323,
  0x52, 0x323, 0x304, 0x72, 0x323, 0x304, 0x52, 0x331,
  0x72, 0x331, 0x53, 0x307, 0x73, 0x307, 0x53, 0x323,
  0x73, 0x323, 0x53, 0x301, 0x307, 0x73, 0x301, 0x307,
  0x53, 0x30c, 0x307, 0x73, 0x30c, 0x307, 0x53, 0x323,
  0x307, 0x73, 0x323, 0x307, 0x54, 0x307, 0x74, 0x307,
  0x54, 0x323, 0x74, 0x323, 0x54, 0x331, 0x74, 0x331,
  0x54, 0x32d, 0x74, 0x32d, 0x55, 0x324, 0x75, 0x324,
  0x55, 0x330, 0x75, 0x330, 0x55, 0x32d, 0x75, 0x32d,
  0x55, 0x303, 0x301, 0x75, 0x303, 0x301, 0x55, 0x304,
  0x308, 0x75, 0x304, 0x308, 0x56, 0x303, 0x76, 0x303,
  0x56, 0x323, 0x76, 0x323, 0x57, 0x300, 0x77, 0x300,
  0x57, 0x301, 0x77, 0x301, 0x57, 0x308, 0x77, 0x308,
  0x57, 0x307, 0x77, 0x307, 0x57, 0x323, 0x77, 0x323,
  0x58, 0x307, 0x78, 0x307, 0x58, 0x308, 0x78, 0x308,
  0x59, 0x307, 0x79, 0x307, 0x5a, 0x302, 0x7a, 0x302,
  0x5a, 0x323, 0x7a, 0x323, 0x5a, 0x331, 0x7a, 0x331,
  0x68, 0x331, 0x74, 0x308, 0x77, 0x30a, 0x79, 0x30a,
  0x17f, 0x307, 0x41, 0x323, 0x61, 0x323, 0x41, 0x309,
  0x61, 0x309, 0x41, 0x302, 0x301, 0x61, 0x302, 0x301,
  0x41, 0x302, 0x300, 0x61, 0x302, 0x300, 0x41, 0x302,
  0x309, 0x61, 0x302, 0x309, 0x41, 0x302, 0x303, 0x61,
  0x302, 0x303, 0x41, 0x323, 0x302, 0x61, 0x323, 0x302,
  0x41, 0x306, 0x301, 0x61, 0x306, 0x301, 0x41, 0x306,
  0x300, 0x61, 0x306, 0x300, 0x41, 0x306, 0x309, 0x61,
  0x306, 0x309, 0x41, 0x306, 0x303, 0x61, 0x306, 0x303,
  0x41, 0x323, 0x306, 0x61, 0x323, 0x306, 0x45, 0x323,
  0x65, 0x323, 0x45, 0x309, 0x65, 0x309, 0x45, 0x303,
  0x65, 0x303, 0x45, 0x302, 0x301, 0x65, 0x302, 0x301,
  0x45, 0x302, 0x300, 0x65, 0x302, 0x300, 0x45, 0x302,
  0x309, 0x65, 0x302, 0x309, 0x45, 0x302, 0x303, 0x65,
  0x302, 0x303, 0x45, 0x323, 0x302, 0x65, 0x323, 0x302,
  0x49, 0x309, 0x69, 0x309, 0x49, 0x323, 0x69, 0x323,
  0x4f, 0x323, 0x6f, 0x323, 0x4f, 0x309, 0x6f, 0x309,
  0x4f, 0x302, 0x301, 0x6f, 0x302, 0x301, 0x4f, 0x302,
  0x300, 0x6f, 0x302, 0x300, 0x4f, 0x302, 0x309, 0x6f,
  0x302, 0x309, 0x4f, 0x302, 0x303, 0x6f, 0x302, 0x303,
  0x4f, 0x323, 0x302, 0x6f, 0x323, 0x302, 0x4f, 0x31b,
  0x301, 0x6f, 0x31b, 0x301, 0x4f, 0x31b, 0x300, 0x6f,
  0x31b, 0x300, 0x4f, 0x31b, 0x309, 0x6f, 0x31b, 0x309,
  0x4f, 0x31b, 0x303, 0x6f, 0x31b, 0x303, 0x4f, 0x31b,
  0x323, 0x6f, 0x31b, 0x323, 0x55, 0x323, 0x75, 0x323,
  0x55, 0x309, 0x75, 0x309, 0x55, 0x31b, 0x301, 0x75,
  0x31b, 0x301, 0x55, 0x31b, 0x300, 0x75, 0x31b, 0x300,
  0x55, 0x31b, 0x309, 0x75, 0x31b, 0x309, 0x55, 0x31b,
  0x303, 0x75, 0x31b, 0x303, 0x55, 0x31b, 0x323, 0x75,
  0x31b, 0x323, 0x59, 0x300, 0x79, 0x300, 0x59, 0x323,
  0x79, 0x323, 0x59, 0x309, 0x79, 0x309, 0x59, 0x303,
  0x79, 0x303, 0x3b1, 0x313, 0x3b1, 0x314, 0x3b1, 0x313,
  0x300, 0x3b1, 0x314, 0x300, 0x3b1, 0x313, 0x301, 0x3b1,
  0x314, 0x301, 0x3b1, 0x313, 0x342, 0x3b1, 0x314, 0x342,
  0x391, 0x313, 0x391, 0x314, 0x391, 0x313, 0x300, 0x391,
  0x314, 0x300, 0x391, 0x313, 0x301, 0x391, 0x314, 0x301,
  0x391, 0x313, 0x342, 0x391, 0x314, 0x342, 0x3b5, 0x313,
  0x3b5, 0x314, 0x3b5, 0x313, 0x300, 0x3b5, 0x314, 0x300,
  0x3b5, 0x313, 0x301, 0x3b5, 0x314, 0x301, 0x395, 0x313,
  0x395, 0x314, 0x395, 0x313, 0x300, 0x395, 0x314, 0x300,
  0x395, 0x313, 0x301, 0x395, 0x314, 0x301, 0x3b7, 0x313,
  0x3b7, 0x314, 0x3b7, 0x313, 0x300, 0x3b7, 0x314, 0x300,
  0x3b7, 0x313, 0x301, 0x3b7, 0x314, 0x301, 0x3b7, 0x313,
  0x342, 0x3b7, 0x314, 0x342, 0x397, 0x313, 0x397, 0x314,
  0x397, 0x313, 0x300, 0x397, 0x314, 0x300, 0x397, 0x313,
  0x301, 0x397, 0x314, 0x301, 0x397, 0x313, 0x342, 0x397,
  0x314, 0x342, 0x3b9, 0x313, 0x3b9, 0x314, 0x3b9, 0x313,
  0x300, 0x3b9, 0x314, 0x300, 0x3b9, 0x313, 0x301, 0x3b9,
  0x314, 0x301, 0x3b9, 0x313, 0x342, 0x3b9, 0x314, 0x342,
  0x399, 0x313, 0x399, 0x314, 0x399, 0x313, 0x300, 0x399,
  0x314, 0x300, 0x399, 0x313, 0x301, 0x399, 0x314, 0x301,
  0x399, 0x313, 0x342, 0x399, 0x314, 0x342, 0x3bf, 0x313,
  0x3bf, 0x314, 0x3bf, 0x313, 0x300, 0x3bf, 0x314, 0x300,
  0x3bf, 0x313, 0x301, 0x3bf, 0x314, 0x301, 0x39f, 0x313,
  0x39f, 0x314, 0x39f, 0x313, 0x300, 0x39f, 0x314, 0x300,
  0x39f, 0x313, 0x301, 0x39f, 0x314, 0x301, 0x3c5, 0x313,
  0x3c5, 0x314, 0x3c5, 0x313, 0x300, 0x3c5, 0x314, 0x300,
  0x3c5, 0x313, 0x301, 0x3c5, 0x314, 0x301, 0x3c5, 0x313,
  0x342, 0x3c5, 0x314, 0x342, 0x3a5, 0x314, 0x3a5, 0x314,
  0x300, 0x3a5, 0x314, 0x301, 0x3a5, 0x314, 0x342, 0x3c9,
  0x313, 0x3c9, 0x314, 0x3c9, 0x313, 0x300, 0x3c9, 0x314,
  0x300, 0x3c9, 0x313, 0x301, 0x3c9, 0x314, 0x301, 0x3c9,
  0x313, 0x342, 0x3c9, 0x314, 0x342, 0x3a9, 0x313, 0x3a9,
  0x314, 0x3a9, 0x313, 0x300, 0x3a9, 0x314, 0x300, 0x3a9,
  0x313, 0x301, 0x3a9, 0x314, 0x301, 0x3a9, 0x313, 0x342,
  0x3a9, 0x314, 0x342, 0x3b1, 0x300, 0x3b1, 0x301, 0x3b5,
  0x300, 0x3b5, 0x301, 0x3b7, 0x300, 0x3b7, 0x301, 0x3b9,
  0x300, 0x3b9, 0x301, 0x3bf, 0x300, 0x3bf, 0x301, 0x3c5,
  0x300, 0x3c5, 0x301, 0x3c9, 0x300, 0x3c9, 0x301, 0x3b1,
  0x313, 0x345, 0x3b1, 0x314, 0x345, 0x3b1, 0x313, 0x300,
  0x345, 0x3b1, 0x314, 0x300, 0x345, 0x3b1, 0x313, 0x301,
  0x345, 0x3b1, 0x314, 0x301, 0x345, 0x3b1, 0x313, 0x342,
  0x345, 0x3b1, 0x314, 0x342, 0x345, 0x391, 0x313, 0x345,
  0x391, 0x314, 0x345, 0x391, 0x313, 0x300, 0x345, 0x391,
  0x314, 0x300, 0x345, 0x391, 0x313, 0x301, 0x345, 0x391,
  0x314, 0x301, 0x345, 0x391, 0x313, 0x342, 0x345, 0x391,
  0x314, 0x342, 0x345, 0x3b7, 0x313, 0x345, 0x3b7, 0x314,
  0x345, 0x3b7, 0x313, 0x300, 0x345, 0x3b7, 0x314, 0x300,
  0x345, 0x3b7, 0x313, 0x301, 0x345, 0x3b7, 0x314, 0x301,
  0x345, 0x3b7, 0x313, 0x342, 0x345, 0x3b7, 0x314, 0x342,
  0x345, 0x397, 0x313, 0x345, 0x397, 0x314, 0x345, 0x397,
  0x313, 0x300, 0x345, 0x397, 0x314, 0x300, 0x345, 0x397,
  0x313, 0x301, 0x345, 0x397, 0x314, 0x301, 0x345, 0x397,
  0x313, 0x342, 0x345, 0x397, 0x314, 0x342, 0x345, 0x3c9,
  0x313, 0x345, 0x3c9, 0x314, 0x345, 0x3c9, 0x313, 0x300,
  0x345, 0x3c9, 0x314, 0x300, 0x345, 0x3c9, 0x313, 0x301,
  0x345, 0x3c9, 0x314, 0x301, 0x345, 0x3c9, 0x313, 0x342,
  0x345, 0x3c9, 0x314, 0x342, 0x345, 0x3a9, 0x313, 0x345,
  0x3a9, 0x314, 0x345, 0x3a9, 0x313, 0x300, 0x345, 0x3a9,
  0x314, 0x300, 0x345, 0x3a9, 0x313, 0x301, 0x345, 0x3a9,
  0x314, 0x301, 0x345, 0x3a9, 0x313, 0x342, 0x345, 0x3a9,
  0x314, 0x342, 0x345, 0x3b1, 0x306, 0x3b1, 0x304, 0x3b1,
  0x300, 0x345, 0x3b1, 0x345, 0x3b1, 0x301, 0x345, 0x3b1,
  0x342, 0x3b1, 0x342, 0x345, 0x391, 0x306, 0x391, 0x304,
  0x391, 0x300, 0x391, 0x301, 0x391, 0x345, 0x3b9, 0xa8,
  0x342, 0x3b7, 0x300, 0x345, 0x3b7, 0x345, 0x3b7, 0x301,
  0x345, 0x3b7, 0x342, 0x3b7, 0x342, 0x345, 0x395, 0x300,
  0x395, 0x301, 0x397, 0x300, 0x397, 0x301, 0x397, 0x345,
  0x1fbf, 0x300, 0x1fbf, 0x301, 0x1fbf, 0x342, 0x3b9, 0x306,
  0x3b9, 0x304, 0x3b9, 0x308, 0x300, 0x3b9, 0x308, 0x301,
  0x3b9, 0x342, 0x3b9, 0x308, 0x342, 0x399, 0x306, 0x399,
  0x304, 0x399, 0x300, 0x399, 0x301, 0x1ffe, 0x300, 0x1ffe,
  0x301, 0x1ffe, 0x342, 0x3c5, 0x306, 0x3c5, 0x304, 0x3c5,
  0x308, 0x300, 0x3c5, 0x308, 0x301, 0x3c1, 0x313, 0x3c1,
  0x314, 0x3c5, 0x342, 0x3c5, 0x308, 0x342, 0x3a5, 0x306,
  0x3a5, 0x304, 0x3a5, 0x300, 0x3a5, 0x301, 0x3a1, 0x314,
  0xa8, 0x300, 0xa8, 0x301, 0x60, 0x3c9, 0x300, 0x345,
  0x3c9, 0x345, 0x3c9, 0x301, 0x345, 0x3c9, 0x342, 0x3c9,
  0x342, 0x345, 0x39f, 0x300, 0x39f, 0x301, 0x3a9, 0x300,
  0x3a9, 0x301, 0x3a9, 0x345, 0xb4, 0x2002, 0x2003, 0x3a9,
  0x4b, 0x41, 0x30a, 0x2190, 0x338, 0x2192, 0x338, 0x2194,
  0x338, 0x21d0, 0x338, 0x21d4, 0x338, 0x21d2, 0x338, 0x2203,
  0x338, 0x2208, 0x338, 0x220b, 0x338, 0x2223, 0x338, 0x2225,
  0x338, 0x223c, 0x338, 0x2243, 0x338, 0x2245, 0x338, 0x2248,
  0x338, 0x3d, 0x338, 0x2261, 0x338, 0x224d, 0x338, 0x3c,
  0x338, 0x3e, 0x338, 0x2264, 0x338, 0x2265, 0x338, 0x2272,
  0x338, 0x2273, 0x338, 0x2276, 0x338, 0x2277, 0x338, 0x227a,
  0x338, 0x227b, 0x338, 0x2282, 0x338, 0x2283, 0x338, 0x2286,
  0x338, 0x2287, 0x338, 0x22a2, 0x338, 0x22a8, 0x338, 0x22a9,
  0x338, 0x22ab, 0x338, 0x227c, 0x338, 0x227d, 0x338, 0x2291,
  0x338, 0x2292, 0x338, 0x22b2, 0x338, 0x22b3, 0x338, 0x22b4,
  0x338, 0x22b5, 0x338, 0x3008, 0x3009, 0x2add, 0x338, 0x304b,
  0x3099, 0x304d, 0x3099, 0x304f, 0x3099, 0x3051, 0x3099, 0x3053,
  0x3099, 0x3055, 0x3099, 0x3057, 0x3099, 0x3059, 0x3099, 0x305b,
  0x3099, 0x305d, 0x3099, 0x305f, 0x3099, 0x3061, 0x3099, 0x3064,
  0x3099, 0x3066, 0x3099, 0x3068, 0x3099, 0x306f, 0x3099, 0x306f,
  0x309a, 0x3072, 0x3099, 0x3072, 0x309a, 0x3075, 0x3099, 0x3075,
  0x309a, 0x3078, 0x3099, 0x3078, 0x309a, 0x307b, 0x3099, 0x307b,
  0x309a, 0x3046, 0x3099, 0x309d, 0x3099, 0x30ab, 0x3099, 0x30ad,
  0x3099, 0x30af, 0x3099, 0x30b1, 0x3099, 0x30b3, 0x3099, 0x30b5,
  0x3099, 0x30b7, 0x3099, 0x30b9, 0x3099, 0x30bb, 0x3099, 0x30bd,
  0x3099, 0x30bf, 0x3099, 0x30c1, 0x3099, 0x30c4, 0x3099, 0x30c6,
  0x3099, 0x30c8, 0x3099, 0x30cf, 0x3099, 0x30cf, 0x309a, 0x30d2,
  0x3099, 0x30d2, 0x309a, 0x30d5, 0x3099, 0x30d5, 0x309a, 0x30d8,
  0x3099, 0x30d8, 0x309a, 0x30db, 0x3099, 0x30db, 0x309a, 0x30a6,
  0x3099, 0x30ef, 0x3099, 0x30f0, 0x3099, 0x30f1, 0x3099, 0x30f2,
  0x3099, 0x30fd, 0x3099, 0x8c48, 0x66f4, 0x8eca, 0x8cc8, 0x6ed1,
  0x4e32, 0x53e5, 0x9f9c, 0x9f9c, 0x5951, 0x91d1, 0x5587, 0x5948,
  0x61f6, 0x7669, 0x7f85, 0x863f, 0x87ba, 0x88f8, 0x908f, 0x6a02,
  0x6d1b, 0x70d9, 0x73de, 0x843d, 0x916a, 0x99f1, 0x4e82, 0x5375,
  0x6b04, 0x721b, 0x862d, 0x9e1e, 0x5d50, 0x6feb, 0x85cd, 0x8964,
  0x62c9, 0x81d8, 0x881f, 0x5eca, 0x6717, 0x6d6a, 0x72fc, 0x90ce,
  0x4f86, 0x51b7, 0x52de, 0x64c4, 0x6ad3, 0x7210, 0x76e7, 0x8001,
  0x8606, 0x865c, 0x8def, 0x9732, 0x9b6f, 0x9dfa, 0x788c, 0x797f,
  0x7da0, 0x83c9, 0x9304, 0x9e7f, 0x8ad6, 0x58df, 0x5f04, 0x7c60,
  0x807e, 0x7262, 0x78ca, 0x8cc2, 0x96f7, 0x58d8, 0x5c62, 0x6a13,
  0x6dda, 0x6f0f, 0x7d2f, 0x7e37, 0x964b, 0x52d2, 0x808b, 0x51dc,
  0x51cc, 0x7a1c, 0x7dbe, 0x83f1, 0x9675, 0x8b80, 0x62cf, 0x6a02,
  0x8afe, 0x4e39, 0x5be7, 0x6012, 0x7387, 0x7570, 0x5317, 0x78fb,
  0x4fbf, 0x5fa9, 0x4e0d, 0x6ccc, 0x6578, 0x7d22, 0x53c3, 0x585e,
  0x7701, 0x8449, 0x8aaa, 0x6bba, 0x8fb0, 0x6c88, 0x62fe, 0x82e5,
  0x63a0, 0x7565, 0x4eae, 0x5169, 0x51c9, 0x6881, 0x7ce7, 0x826f,
  0x8ad2, 0x91cf, 0x52f5, 0x5442, 0x5973, 0x5eec, 0x65c5, 0x6ffe,
  0x792a, 0x95ad, 0x9a6a, 0x9e97, 0x9ece, 0x529b, 0x66c6, 0x6b77,
  0x8f62, 0x5e74, 0x6190, 0x6200, 0x649a, 0x6f23, 0x7149, 0x7489,
  0x79ca, 0x7df4, 0x806f, 0x8f26, 0x84ee, 0x9023, 0x934a, 0x5217,
  0x52a3, 0x54bd, 0x70c8, 0x88c2, 0x8aaa, 0x5ec9, 0x5ff5, 0x637b,
  0x6bae, 0x7c3e, 0x7375, 0x4ee4, 0x56f9, 0x5be7, 0x5dba, 0x601c,
  0x73b2, 0x7469, 0x7f9a, 0x8046, 0x9234, 0x96f6, 0x9748, 0x9818,
  0x4f8b, 0x79ae, 0x91b4, 0x96b8, 0x60e1, 0x4e86, 0x50da, 0x5bee,
  0x5c3f, 0x6599, 0x6a02, 0x71ce, 0x7642, 0x84fc, 0x907c, 0x9f8d,
  0x6688, 0x962e, 0x5289, 0x677b, 0x67f3, 0x6d41, 0x6e9c, 0x7409,
  0x7559, 0x786b, 0x7d10, 0x985e, 0x516d, 0x622e, 0x9678, 0x502b,
  0x5d19, 0x6dea, 0x8f2a, 0x5f8b, 0x6144, 0x6817, 0x7387, 0x9686,
  0x5229, 0x540f, 0x5c65, 0x6613, 0x674e, 0x68a8, 0x6ce5, 0x7406,
  0x75e2, 0x7f79, 0x88cf, 0x88e1, 0x91cc, 0x96e2, 0x533f, 0x6eba,
  0x541d, 0x71d0, 0x7498, 0x85fa, 0x96a3, 0x9c57, 0x9e9f, 0x6797,
  0x6dcb, 0x81e8, 0x7acb, 0x7b20, 0x7c92, 0x72c0, 0x7099, 0x8b58,
  0x4ec0, 0x8336, 0x523a, 0x5207, 0x5ea6, 0x62d3, 0x7cd6, 0x5b85,
  0x6d1e, 0x66b4, 0x8f3b, 0x884c, 0x964d, 0x898b, 0x5ed3, 0x5140,
  0x55c0, 0x585a, 0x6674, 0x51de, 0x732a, 0x76ca, 0x793c, 0x795e,
  0x7965, 0x798f, 0x9756, 0x7cbe, 0x7fbd, 0x8612, 0x8af8, 0x9038,
  0x90fd, 0x98ef, 0x98fc, 0x9928, 0x9db4, 0x4fae, 0x50e7, 0x514d,
  0x52c9, 0x52e4, 0x5351, 0x559d, 0x5606, 0x5668, 0x5840, 0x58a8,
  0x5c64, 0x5c6e, 0x6094, 0x6168, 0x618e, 0x61f2, 0x654f, 0x65e2,
  0x6691, 0x6885, 0x6d77, 0x6e1a, 0x6f22, 0x716e, 0x722b, 0x7422,
  0x7891, 0x793e, 0x7949, 0x7948, 0x7950, 0x7956, 0x795d, 0x798d,
  0x798e, 0x7a40, 0x7a81, 0x7bc0, 0x7df4, 0x7e09, 0x7e41, 0x7f72,
  0x8005, 0x81ed, 0x8279, 0x8279, 0x8457, 0x8910, 0x8996, 0x8b01,
  0x8b39, 0x8cd3, 0x8d08, 0x8fb6, 0x9038, 0x96e3, 0x97ff, 0x983b,
  0x5d9, 0x5b4, 0x5f2, 0x5b7, 0x5e9, 0x5c1, 0x5e9, 0x5c2,
  0x5e9, 0x5bc, 0x5c1, 0x5e9, 0x5bc, 0x5c2, 0x5d0, 0x5b7,
  0x5d0, 0x5b8, 0x5d0, 0x5bc, 0x5d1, 0x5bc, 0x5d2, 0x5bc,
  0x5d3, 0x5bc, 0x5d4, 0x5bc, 0x5d5, 0x5bc, 0x5d6, 0x5bc,
  0x5d8, 0x5bc, 0x5d9, 0x5bc, 0x5da, 0x5bc, 0x5db, 0x5bc,
  0x5dc, 0x5bc, 0x5de, 0x5bc, 0x5e0, 0x5bc, 0x5e1, 0x5bc,
  0x5e3, 0x5bc, 0x5e4, 0x5bc, 0x5e6, 0x5bc, 0x5e7, 0x5bc,
  0x5e8, 0x5bc, 0x5e9, 0x5bc, 0x5ea, 0x5bc, 0x5d5, 0x5b9,
  0x5d1, 0x5bf, 0x5db, 0x5bf, 0x5e4, 0x5bf, 0x1d157, 0x1d165,
  0x1d158, 0x1d165, 0x1d158, 0x1d165, 0x1d16e, 0x1d158, 0x1d165, 0x1d16f,
  0x1d158, 0x1d165, 0x1d170, 0x1d158, 0x1d165, 0x1d171, 0x1d158, 0x1d165,
  0x1d172, 0x1d1b9, 0x1d165, 0x1d1ba, 0x1d165, 0x1d1b9, 0x1d165, 0x1d16e,
  0x1d1ba, 0x1d165, 0x1d16e, 0x1d1b9, 0x1d165, 0x1d16f, 0x1d1ba, 0x1d165,
  0x1d16f, 0x4e3d, 0x4e38, 0x4e41, 0x20122, 0x4f60, 0x4fae, 0x4fbb,
  0x5002, 0x507a, 0x5099, 0x50e7, 0x50cf, 0x349e, 0x2063a, 0x514d,
  0x5154, 0x5164, 0x5177, 0x2051c, 0x34b9, 0x5167, 0x518d, 0x2054b,
  0x5197, 0x51a4, 0x4ecc, 0x51ac, 0x51b5, 0x291df, 0x51f5, 0x5203,
  0x34df, 0x523b, 0x5246, 0x5272, 0x5277, 0x3515, 0x52c7, 0x52c9,
  0x52e4, 0x52fa, 0x5305, 0x5306, 0x5317, 0x5349, 0x5351, 0x535a,
  0x5373, 0x537d, 0x537f, 0x537f, 0x537f, 0x20a2c, 0x7070, 0x53ca,
  0x53df, 0x20b63, 0x53eb, 0x53f1, 0x5406, 0x549e, 0x5438, 0x5448,
  0x5468, 0x54a2, 0x54f6, 0x5510, 0x5553, 0x5563, 0x5584, 0x5584,
  0x5599, 0x55ab, 0x55b3, 0x55c2, 0x5716, 0x5606, 0x5717, 0x5651,
  0x5674, 0x5207, 0x58ee, 0x57ce, 0x57f4, 0x580d, 0x578b, 0x5832,
  0x5831, 0x58ac, 0x214e4, 0x58f2, 0x58f7, 0x5906, 0x591a, 0x5922,
  0x5962, 0x216a8, 0x216ea, 0x59ec, 0x5a1b, 0x5a27, 0x59d8, 0x5a66,
  0x36ee, 0x36fc, 0x5b08, 0x5b3e, 0x5b3e, 0x219c8, 0x5bc3, 0x5bd8,
  0x5be7, 0x5bf3, 0x21b18, 0x5bff, 0x5c06, 0x5f53, 0x5c22, 0x3781,
  0x5c60, 0x5c6e, 0x5cc0, 0x5c8d, 0x21de4, 0x5d43, 0x21de6, 0x5d6e,
  0x5d6b, 0x5d7c, 0x5de1, 0x5de2, 0x382f, 0x5dfd, 0x5e28, 0x5e3d,
  0x5e69, 0x3862, 0x22183, 0x387c, 0x5eb0, 0x5eb3, 0x5eb6, 0x5eca,
  0x2a392, 0x5efe, 0x22331, 0x22331, 0x8201, 0x5f22, 0x5f22, 0x38c7,
  0x232b8, 0x261da, 0x5f62, 0x5f6b, 0x38e3, 0x5f9a, 0x5fcd, 0x5fd7,
  0x5ff9, 0x6081, 0x393a, 0x391c, 0x6094, 0x226d4, 0x60c7, 0x6148,
  0x614c, 0x614e, 0x614c, 0x617a, 0x618e, 0x61b2, 0x61a4, 0x61af,
  0x61de, 0x61f2, 0x61f6, 0x6210, 0x621b, 0x625d, 0x62b1, 0x62d4,
  0x6350, 0x22b0c, 0x633d, 0x62fc, 0x6368, 0x6383, 0x63e4, 0x22bf1,
  0x6422, 0x63c5, 0x63a9, 0x3a2e, 0x6469, 0x647e, 0x649d, 0x6477,
  0x3a6c, 0x654f, 0x656c, 0x2300a, 0x65e3, 0x66f8, 0x6649, 0x3b19,
  0x6691, 0x3b08, 0x3ae4, 0x5192, 0x5195, 0x6700, 0x669c, 0x80ad,
  0x43d9, 0x6717, 0x671b, 0x6721, 0x675e, 0x6753, 0x233c3, 0x3b49,
  0x67fa, 0x6785, 0x6852, 0x6885, 0x2346d, 0x688e, 0x681f, 0x6914,
  0x3b9d, 0x6942, 0x69a3, 0x69ea, 0x6aa8, 0x236a3, 0x6adb, 0x3c18,
  0x6b21, 0x238a7, 0x6b54, 0x3c4e, 0x6b72, 0x6b9f, 0x6bba, 0x6bbb,
  0x23a8d, 0x21d0b, 0x23afa, 0x6c4e, 0x23cbc, 0x6cbf, 0x6ccd, 0x6c67,
  0x6d16, 0x6d3e, 0x6d77, 0x6d41, 0x6d69, 0x6d78, 0x6d85, 0x23d1e,
  0x6d34, 0x6e2f, 0x6e6e, 0x3d33, 0x6ecb, 0x6ec7, 0x23ed1, 0x6df9,
  0x6f6e, 0x23f5e, 0x23f8e, 0x6fc6, 0x7039, 0x701e, 0x701b, 0x3d96,
  0x704a, 0x707d, 0x7077, 0x70ad, 0x20525, 0x7145, 0x24263, 0x719c,
  0x243ab, 0x7228, 0x7235, 0x7250, 0x24608, 0x7280, 0x7295, 0x24735,
  0x24814, 0x737a, 0x738b, 0x3eac, 0x73a5, 0x3eb8, 0x3eb8, 0x7447,
  0x745c, 0x7471, 0x7485, 0x74ca, 0x3f1b, 0x7524, 0x24c36, 0x753e,
  0x24c92, 0x7570, 0x2219f, 0x7610, 0x24fa1, 0x24fb8, 0x25044, 0x3ffc,
  0x4008, 0x76f4, 0x250f3, 0x250f2, 0x25119, 0x25133, 0x771e, 0x771f,
  0x771f, 0x774a, 0x4039, 0x778b, 0x4046, 0x4096, 0x2541d, 0x784e,
  0x788c, 0x78cc, 0x40e3, 0x25626, 0x7956, 0x2569a, 0x256c5, 0x798f,
  0x79eb, 0x412f, 0x7a40, 0x7a4a, 0x7a4f, 0x2597c, 0x25aa7, 0x25aa7,
  0x7aee, 0x4202, 0x25bab, 0x7bc6, 0x7bc9, 0x4227, 0x25c80, 0x7cd2,
  0x42a0, 0x7ce8, 0x7ce3, 0x7d00, 0x25f86, 0x7d63, 0x4301, 0x7dc7,
  0x7e02, 0x7e45, 0x4334, 0x26228, 0x26247, 0x4359, 0x262d9, 0x7f7a,
  0x2633e, 0x7f95, 0x7ffa, 0x8005, 0x264da, 0x26523, 0x8060, 0x265a8,
  0x8070, 0x2335f, 0x43d5, 0x80b2, 0x8103, 0x440b, 0x813e, 0x5ab5,
  0x267a7, 0x267b5, 0x23393, 0x2339c, 0x8201, 0x8204, 0x8f9e, 0x446b,
  0x8291, 0x828b, 0x829d, 0x52b3, 0x82b1, 0x82b3, 0x82bd, 0x82e6,
  0x26b3c, 0x82e5, 0x831d, 0x8363, 0x83ad, 0x8323, 0x83bd, 0x83e7,
  0x8457, 0x8353, 0x83ca, 0x83cc, 0x83dc, 0x26c36, 0x26d6b, 0x26cd5,
  0x452b, 0x84f1, 0x84f3, 0x8516, 0x273ca, 0x8564, 0x26f2c, 0x455d,
  0x4561, 0x26fb1, 0x270d2, 0x456b, 0x8650, 0x865c, 0x8667, 0x8669,
  0x86a9, 0x8688, 0x870e, 0x86e2, 0x8779, 0x8728, 0x876b, 0x8786,
  0x45d7, 0x87e1, 0x8801, 0x45f9, 0x8860, 0x8863, 0x27667, 0x88d7,
  0x88de, 0x4635, 0x88fa, 0x34bb, 0x278ae, 0x27966, 0x46be, 0x46c7,
  0x8aa0, 0x8aed, 0x8b8a, 0x8c55, 0x27ca8, 0x8cab, 0x8cc1, 0x8d1b,
  0x8d77, 0x27f2f, 0x20804, 0x8dcb, 0x8dbc, 0x8df0, 0x208de, 0x8ed4,
  0x8f38, 0x285d2, 0x285ed, 0x9094, 0x90f1, 0x9111, 0x2872e, 0x911b,
  0x9238, 0x92d7, 0x92d8, 0x927c, 0x93f9, 0x9415, 0x28bfa, 0x958b,
  0x4995, 0x95b7, 0x28d77, 0x49e6, 0x96c3, 0x5db2, 0x9723, 0x29145,
  0x2921a, 0x4a6e, 0x4a76, 0x97e0, 0x2940a, 0x4ab2, 0x29496, 0x980b,
  0x980b, 0x9829, 0x295b6, 0x98e2, 0x4b33, 0x9929, 0x99a7, 0x99c2,
  0x99fe, 0x4bce, 0x29b30, 0x9b12, 0x9c40, 0x9cfd, 0x4cce, 0x4ced,
  0x9d67, 0x2a0ce, 0x4cf8, 0x2a105, 0x2a20e, 0x2a291, 0x9ebb, 0x4d56,
  0x9ef9, 0x9efe, 0x9f05, 0x9f0f, 0x9f16, 0x9f3b, 0x2a600
};

static decomp_block_t unigen_decomp_block_0x0[256] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 0 },
  { 2, 2 },
  { 2, 4 },
  { 2, 6 },
  { 2, 8 },
  { 2, 10 },
  { 0, 0 },
  { 2, 12 },
  { 2, 14 },
  { 2, 16 },
  { 2, 18 },
  { 2, 20 },
  { 2, 22 },
  { 2, 24 },
  { 2, 26 },
  { 2, 28 },
  { 0, 0 },
  { 2, 30 },
  { 2, 32 },
  { 2, 34 },
  { 2, 36 },
  { 2, 38 },
  { 2, 40 },
  { 0, 0 },
  { 0, 0 },
  { 2, 42 },
  { 2, 44 },
  { 2, 46 },
  { 2, 48 },
  { 2, 50 },
  { 0, 0 },
  { 0, 0 },
  { 2, 52 },
  { 2, 54 },
  { 2, 56 },
  { 2, 58 },
  { 2, 60 },
  { 2, 62 },
  { 0, 0 },
  { 2, 64 },
  { 2, 66 },
  { 2, 68 },
  { 2, 70 },
  { 2, 72 },
  { 2, 74 },
  { 2, 76 },
  { 2, 78 },
  { 2, 80 },
  { 0, 0 },
  { 2, 82 },
  { 2, 84 },
  { 2, 86 },
  { 2, 88 },
  { 2, 90 },
  { 2, 92 },
  { 0, 0 },
  { 0, 0 },
  { 2, 94 },
  { 2, 96 },
  { 2, 98 },
  { 2, 100 },
  { 2, 102 },
  { 0, 0 },
  { 2, 104 },
};

static decomp_block_t unigen_decomp_block_0x1[256] = {
  { 2, 106 },
  { 2, 108 },
  { 2, 110 },
  { 2, 112 },
  { 2, 114 },
  { 2, 116 },
  { 2, 118 },
  { 2, 120 },
  { 2, 122 },
  { 2, 124 },
  { 2, 126 },
  { 2, 128 },
  { 2, 130 },
  { 2, 132 },
  { 2, 134 },
  { 2, 136 },
  { 0, 0 },
  { 0, 0 },
  { 2, 138 },
  { 2, 140 },
  { 2, 142 },
  { 2, 144 },
  { 2, 146 },
  { 2, 148 },
  { 2, 150 },
  { 2, 152 },
  { 2, 154 },
  { 2, 156 },
  { 2, 158 },
  { 2, 160 },
  { 2, 162 },
  { 2, 164 },
  { 2, 166 },
  { 2, 168 },
  { 2, 170 },
  { 2, 172 },
  { 2, 174 },
  { 2, 176 },
  { 0, 0 },
  { 0, 0 },
  { 2, 178 },
  { 2, 180 },
  { 2, 182 },
  { 2, 184 },
  { 2, 186 },
  { 2, 188 },
  { 2, 190 },
  { 2, 192 },
  { 2, 194 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 196 },
  { 2, 198 },
  { 2, 200 },
  { 2, 202 },
  { 0, 0 },
  { 2, 204 },
  { 2, 206 },
  { 2, 208 },
  { 2, 210 },
  { 2, 212 },
  { 2, 214 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 216 },
  { 2, 218 },
  { 2, 220 },
  { 2, 222 },
  { 2, 224 },
  { 2, 226 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 228 },
  { 2, 230 },
  { 2, 232 },
  { 2, 234 },
  { 2, 236 },
  { 2, 238 },
  { 0, 0 },
  { 0, 0 },
  { 2, 240 },
  { 2, 242 },
  { 2, 244 },
  { 2, 246 },
  { 2, 248 },
  { 2, 250 },
  { 2, 252 },
  { 2, 254 },
  { 2, 256 },
  { 2, 258 },
  { 2, 260 },
  { 2, 262 },
  { 2, 264 },
  { 2, 266 },
  { 2, 268 },
  { 2, 270 },
  { 2, 272 },
  { 2, 274 },
  { 0, 0 },
  { 0, 0 },
  { 2, 276 },
  { 2, 278 },
  { 2, 280 },
  { 2, 282 },
  { 2, 284 },
  { 2, 286 },
  { 2, 288 },
  { 2, 290 },
  { 2, 292 },
  { 2, 294 },
  { 2, 296 },
  { 2, 298 },
  { 2, 300 },
  { 2, 302 },
  { 2, 304 },
  { 2, 306 },
  { 2, 308 },
  { 2, 310 },
  { 2, 312 },
  { 2, 314 },
  { 2, 316 },
  { 2, 318 },
  { 2, 320 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 322 },
  { 2, 324 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 326 },
  { 2, 328 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 330 },
  { 2, 332 },
  { 2, 334 },
  { 2, 336 },
  { 2, 338 },
  { 2, 340 },
  { 2, 342 },
  { 2, 344 },
  { 3, 346 },
  { 3, 349 },
  { 3, 352 },
  { 3, 355 },
  { 3, 358 },
  { 3, 361 },
  { 3, 364 },
  { 3, 367 },
  { 0, 0 },
  { 3, 370 },
  { 3, 373 },
  { 3, 376 },
  { 3, 379 },
  { 2, 382 },
  { 2, 384 },
  { 0, 0 },
  { 0, 0 },
  { 2, 386 },
  { 2, 388 },
  { 2, 390 },
  { 2, 392 },
  { 2, 394 },
  { 2, 396 },
  { 3, 398 },
  { 3, 401 },
  { 2, 404 },
  { 2, 406 },
  { 2, 408 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 410 },
  { 2, 412 },
  { 0, 0 },
  { 0, 0 },
  { 2, 414 },
  { 2, 416 },
  { 3, 418 },
  { 3, 421 },
  { 2, 424 },
  { 2, 426 },
  { 2, 428 },
  { 2, 430 },
};

static decomp_block_t unigen_decomp_block_0x2[256] = {
  { 2, 432 },
  { 2, 434 },
  { 2, 436 },
  { 2, 438 },
  { 2, 440 },
  { 2, 442 },
  { 2, 444 },
  { 2, 446 },
  { 2, 448 },
  { 2, 450 },
  { 2, 452 },
  { 2, 454 },
  { 2, 456 },
  { 2, 458 },
  { 2, 460 },
  { 2, 462 },
  { 2, 464 },
  { 2, 466 },
  { 2, 468 },
  { 2, 470 },
  { 2, 472 },
  { 2, 474 },
  { 2, 476 },
  { 2, 478 },
  { 2, 480 },
  { 2, 482 },
  { 2, 484 },
  { 2, 486 },
  { 0, 0 },
  { 0, 0 },
  { 2, 488 },
  { 2, 490 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 492 },
  { 2, 494 },
  { 2, 496 },
  { 2, 498 },
  { 3, 500 },
  { 3, 503 },
  { 3, 506 },
  { 3, 509 },
  { 2, 512 },
  { 2, 514 },
  { 3, 516 },
  { 3, 519 },
  { 2, 522 },
  { 2, 524 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x3[256] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 1, 526 },
  { 1, 527 },
  { 0, 0 },
  { 1, 528 },
  { 2, 529 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 1, 531 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 1, 532 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 533 },
  { 2, 535 },
  { 1, 537 },
  { 2, 538 },
  { 2, 540 },
  { 2, 542 },
  { 0, 0 },
  { 2, 544 },
  { 0, 0 },
  { 2, 546 },
  { 2, 548 },
  { 3, 550 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 553 },
  { 2, 555 },
  { 2, 557 },
  { 2, 559 },
  { 2, 561 },
  { 2, 563 },
  { 3, 565 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 568 },
  { 2, 570 },
  { 2, 572 },
  { 2, 574 },
  { 2, 576 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 578 },
  { 2, 580 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x4[256] = {
  { 2, 582 },
  { 2, 584 },
  { 0, 0 },
  { 2, 586 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 588 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 590 },
  { 2, 592 },
  { 2, 594 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 596 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 598 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 600 },
  { 2, 602 },
  { 0, 0 },
  { 2, 604 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 606 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 608 },
  { 2, 610 },
  { 2, 612 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 614 },
  { 2, 616 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 618 },
  { 2, 620 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 622 },
  { 2, 624 },
  { 2, 626 },
  { 2, 628 },
  { 0, 0 },
  { 0, 0 },
  { 2, 630 },
  { 2, 632 },
  { 0, 0 },
  { 0, 0 },
  { 2, 634 },
  { 2, 636 },
  { 2, 638 },
  { 2, 640 },
  { 2, 642 },
  { 2, 644 },
  { 0, 0 },
  { 0, 0 },
  { 2, 646 },
  { 2, 648 },
  { 2, 650 },
  { 2, 652 },
  { 2, 654 },
  { 2, 656 },
  { 0, 0 },
  { 0, 0 },
  { 2, 658 },
  { 2, 660 },
  { 2, 662 },
  { 2, 664 },
  { 2, 666 },
  { 2, 668 },
  { 2, 670 },
  { 2, 672 },
  { 2, 674 },
  { 2, 676 },
  { 2, 678 },
  { 2, 680 },
  { 0, 0 },
  { 0, 0 },
  { 2, 682 },
  { 2, 684 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x1e[256] = {
  { 2, 828 },
  { 2, 830 },
  { 2, 832 },
  { 2, 834 },
  { 2, 836 },
  { 2, 838 },
  { 2, 840 },
  { 2, 842 },
  { 3, 844 },
  { 3, 847 },
  { 2, 850 },
  { 2, 852 },
  { 2, 854 },
  { 2, 856 },
  { 2, 858 },
  { 2, 860 },
  { 2, 862 },
  { 2, 864 },
  { 2, 866 },
  { 2, 868 },
  { 3, 870 },
  { 3, 873 },
  { 3, 876 },
  { 3, 879 },
  { 2, 882 },
  { 2, 884 },
  { 2, 886 },
  { 2, 888 },
  { 3, 890 },
  { 3, 893 },
  { 2, 896 },
  { 2, 898 },
  { 2, 900 },
  { 2, 902 },
  { 2, 904 },
  { 2, 906 },
  { 2, 908 },
  { 2, 910 },
  { 2, 912 },
  { 2, 914 },
  { 2, 916 },
  { 2, 918 },
  { 2, 920 },
  { 2, 922 },
  { 2, 924 },
  { 2, 926 },
  { 3, 928 },
  { 3, 931 },
  { 2, 934 },
  { 2, 936 },
  { 2, 938 },
  { 2, 940 },
  { 2, 942 },
  { 2, 944 },
  { 2, 946 },
  { 2, 948 },
  { 3, 950 },
  { 3, 953 },
  { 2, 956 },
  { 2, 958 },
  { 2, 960 },
  { 2, 962 },
  { 2, 964 },
  { 2, 966 },
  { 2, 968 },
  { 2, 970 },
  { 2, 972 },
  { 2, 974 },
  { 2, 976 },
  { 2, 978 },
  { 2, 980 },
  { 2, 982 },
  { 2, 984 },
  { 2, 986 },
  { 2, 988 },
  { 2, 990 },
  { 3, 992 },
  { 3, 995 },
  { 3, 998 },
  { 3, 1001 },
  { 3, 1004 },
  { 3, 1007 },
  { 3, 1010 },
  { 3, 1013 },
  { 2, 1016 },
  { 2, 1018 },
  { 2, 1020 },
  { 2, 1022 },
  { 2, 1024 },
  { 2, 1026 },
  { 2, 1028 },
  { 2, 1030 },
  { 3, 1032 },
  { 3, 1035 },
  { 2, 1038 },
  { 2, 1040 },
  { 2, 1042 },
  { 2, 1044 },
  { 2, 1046 },
  { 2, 1048 },
  { 3, 1050 },
  { 3, 1053 },
  { 3, 1056 },
  { 3, 1059 },
  { 3, 1062 },
  { 3, 1065 },
  { 2, 1068 },
  { 2, 1070 },
  { 2, 1072 },
  { 2, 1074 },
  { 2, 1076 },
  { 2, 1078 },
  { 2, 1080 },
  { 2, 1082 },
  { 2, 1084 },
  { 2, 1086 },
  { 2, 1088 },
  { 2, 1090 },
  { 2, 1092 },
  { 2, 1094 },
  { 3, 1096 },
  { 3, 1099 },
  { 3, 1102 },
  { 3, 1105 },
  { 2, 1108 },
  { 2, 1110 },
  { 2, 1112 },
  { 2, 1114 },
  { 2, 1116 },
  { 2, 1118 },
  { 2, 1120 },
  { 2, 1122 },
  { 2, 1124 },
  { 2, 1126 },
  { 2, 1128 },
  { 2, 1130 },
  { 2, 1132 },
  { 2, 1134 },
  { 2, 1136 },
  { 2, 1138 },
  { 2, 1140 },
  { 2, 1142 },
  { 2, 1144 },
  { 2, 1146 },
  { 2, 1148 },
  { 2, 1150 },
  { 2, 1152 },
  { 2, 1154 },
  { 2, 1156 },
  { 2, 1158 },
  { 2, 1160 },
  { 2, 1162 },
  { 2, 1164 },
  { 2, 1166 },
  { 0, 0 },
  { 2, 1168 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1170 },
  { 2, 1172 },
  { 2, 1174 },
  { 2, 1176 },
  { 3, 1178 },
  { 3, 1181 },
  { 3, 1184 },
  { 3, 1187 },
  { 3, 1190 },
  { 3, 1193 },
  { 3, 1196 },
  { 3, 1199 },
  { 3, 1202 },
  { 3, 1205 },
  { 3, 1208 },
  { 3, 1211 },
  { 3, 1214 },
  { 3, 1217 },
  { 3, 1220 },
  { 3, 1223 },
  { 3, 1226 },
  { 3, 1229 },
  { 3, 1232 },
  { 3, 1235 },
  { 2, 1238 },
  { 2, 1240 },
  { 2, 1242 },
  { 2, 1244 },
  { 2, 1246 },
  { 2, 1248 },
  { 3, 1250 },
  { 3, 1253 },
  { 3, 1256 },
  { 3, 1259 },
  { 3, 1262 },
  { 3, 1265 },
  { 3, 1268 },
  { 3, 1271 },
  { 3, 1274 },
  { 3, 1277 },
  { 2, 1280 },
  { 2, 1282 },
  { 2, 1284 },
  { 2, 1286 },
  { 2, 1288 },
  { 2, 1290 },
  { 2, 1292 },
  { 2, 1294 },
  { 3, 1296 },
  { 3, 1299 },
  { 3, 1302 },
  { 3, 1305 },
  { 3, 1308 },
  { 3, 1311 },
  { 3, 1314 },
  { 3, 1317 },
  { 3, 1320 },
  { 3, 1323 },
  { 3, 1326 },
  { 3, 1329 },
  { 3, 1332 },
  { 3, 1335 },
  { 3, 1338 },
  { 3, 1341 },
  { 3, 1344 },
  { 3, 1347 },
  { 3, 1350 },
  { 3, 1353 },
  { 2, 1356 },
  { 2, 1358 },
  { 2, 1360 },
  { 2, 1362 },
  { 3, 1364 },
  { 3, 1367 },
  { 3, 1370 },
  { 3, 1373 },
  { 3, 1376 },
  { 3, 1379 },
  { 3, 1382 },
  { 3, 1385 },
  { 3, 1388 },
  { 3, 1391 },
  { 2, 1394 },
  { 2, 1396 },
  { 2, 1398 },
  { 2, 1400 },
  { 2, 1402 },
  { 2, 1404 },
  { 2, 1406 },
  { 2, 1408 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x1f[256] = {
  { 2, 1410 },
  { 2, 1412 },
  { 3, 1414 },
  { 3, 1417 },
  { 3, 1420 },
  { 3, 1423 },
  { 3, 1426 },
  { 3, 1429 },
  { 2, 1432 },
  { 2, 1434 },
  { 3, 1436 },
  { 3, 1439 },
  { 3, 1442 },
  { 3, 1445 },
  { 3, 1448 },
  { 3, 1451 },
  { 2, 1454 },
  { 2, 1456 },
  { 3, 1458 },
  { 3, 1461 },
  { 3, 1464 },
  { 3, 1467 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1470 },
  { 2, 1472 },
  { 3, 1474 },
  { 3, 1477 },
  { 3, 1480 },
  { 3, 1483 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1486 },
  { 2, 1488 },
  { 3, 1490 },
  { 3, 1493 },
  { 3, 1496 },
  { 3, 1499 },
  { 3, 1502 },
  { 3, 1505 },
  { 2, 1508 },
  { 2, 1510 },
  { 3, 1512 },
  { 3, 1515 },
  { 3, 1518 },
  { 3, 1521 },
  { 3, 1524 },
  { 3, 1527 },
  { 2, 1530 },
  { 2, 1532 },
  { 3, 1534 },
  { 3, 1537 },
  { 3, 1540 },
  { 3, 1543 },
  { 3, 1546 },
  { 3, 1549 },
  { 2, 1552 },
  { 2, 1554 },
  { 3, 1556 },
  { 3, 1559 },
  { 3, 1562 },
  { 3, 1565 },
  { 3, 1568 },
  { 3, 1571 },
  { 2, 1574 },
  { 2, 1576 },
  { 3, 1578 },
  { 3, 1581 },
  { 3, 1584 },
  { 3, 1587 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1590 },
  { 2, 1592 },
  { 3, 1594 },
  { 3, 1597 },
  { 3, 1600 },
  { 3, 1603 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1606 },
  { 2, 1608 },
  { 3, 1610 },
  { 3, 1613 },
  { 3, 1616 },
  { 3, 1619 },
  { 3, 1622 },
  { 3, 1625 },
  { 0, 0 },
  { 2, 1628 },
  { 0, 0 },
  { 3, 1630 },
  { 0, 0 },
  { 3, 1633 },
  { 0, 0 },
  { 3, 1636 },
  { 2, 1639 },
  { 2, 1641 },
  { 3, 1643 },
  { 3, 1646 },
  { 3, 1649 },
  { 3, 1652 },
  { 3, 1655 },
  { 3, 1658 },
  { 2, 1661 },
  { 2, 1663 },
  { 3, 1665 },
  { 3, 1668 },
  { 3, 1671 },
  { 3, 1674 },
  { 3, 1677 },
  { 3, 1680 },
  { 2, 1683 },
  { 2, 1685 },
  { 2, 1687 },
  { 2, 1689 },
  { 2, 1691 },
  { 2, 1693 },
  { 2, 1695 },
  { 2, 1697 },
  { 2, 1699 },
  { 2, 1701 },
  { 2, 1703 },
  { 2, 1705 },
  { 2, 1707 },
  { 2, 1709 },
  { 0, 0 },
  { 0, 0 },
  { 3, 1711 },
  { 3, 1714 },
  { 4, 1717 },
  { 4, 1721 },
  { 4, 1725 },
  { 4, 1729 },
  { 4, 1733 },
  { 4, 1737 },
  { 3, 1741 },
  { 3, 1744 },
  { 4, 1747 },
  { 4, 1751 },
  { 4, 1755 },
  { 4, 1759 },
  { 4, 1763 },
  { 4, 1767 },
  { 3, 1771 },
  { 3, 1774 },
  { 4, 1777 },
  { 4, 1781 },
  { 4, 1785 },
  { 4, 1789 },
  { 4, 1793 },
  { 4, 1797 },
  { 3, 1801 },
  { 3, 1804 },
  { 4, 1807 },
  { 4, 1811 },
  { 4, 1815 },
  { 4, 1819 },
  { 4, 1823 },
  { 4, 1827 },
  { 3, 1831 },
  { 3, 1834 },
  { 4, 1837 },
  { 4, 1841 },
  { 4, 1845 },
  { 4, 1849 },
  { 4, 1853 },
  { 4, 1857 },
  { 3, 1861 },
  { 3, 1864 },
  { 4, 1867 },
  { 4, 1871 },
  { 4, 1875 },
  { 4, 1879 },
  { 4, 1883 },
  { 4, 1887 },
  { 2, 1891 },
  { 2, 1893 },
  { 3, 1895 },
  { 2, 1898 },
  { 3, 1900 },
  { 0, 0 },
  { 2, 1903 },
  { 3, 1905 },
  { 2, 1908 },
  { 2, 1910 },
  { 2, 1912 },
  { 2, 1914 },
  { 2, 1916 },
  { 0, 0 },
  { 1, 1918 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1919 },
  { 3, 1921 },
  { 2, 1924 },
  { 3, 1926 },
  { 0, 0 },
  { 2, 1929 },
  { 3, 1931 },
  { 2, 1934 },
  { 2, 1936 },
  { 2, 1938 },
  { 2, 1940 },
  { 2, 1942 },
  { 2, 1944 },
  { 2, 1946 },
  { 2, 1948 },
  { 2, 1950 },
  { 2, 1952 },
  { 3, 1954 },
  { 3, 1957 },
  { 0, 0 },
  { 0, 0 },
  { 2, 1960 },
  { 3, 1962 },
  { 2, 1965 },
  { 2, 1967 },
  { 2, 1969 },
  { 2, 1971 },
  { 0, 0 },
  { 2, 1973 },
  { 2, 1975 },
  { 2, 1977 },
  { 2, 1979 },
  { 2, 1981 },
  { 3, 1983 },
  { 3, 1986 },
  { 2, 1989 },
  { 2, 1991 },
  { 2, 1993 },
  { 3, 1995 },
  { 2, 1998 },
  { 2, 2000 },
  { 2, 2002 },
  { 2, 2004 },
  { 2, 2006 },
  { 2, 2008 },
  { 2, 2010 },
  { 1, 2012 },
  { 0, 0 },
  { 0, 0 },
  { 3, 2013 },
  { 2, 2016 },
  { 3, 2018 },
  { 0, 0 },
  { 2, 2021 },
  { 3, 2023 },
  { 2, 2026 },
  { 2, 2028 },
  { 2, 2030 },
  { 2, 2032 },
  { 2, 2034 },
  { 1, 2036 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x22[256] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2055 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2057 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2059 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2061 },
  { 0, 0 },
  { 2, 2063 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2065 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2067 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2069 },
  { 0, 0 },
  { 2, 2071 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2073 },
  { 0, 0 },
  { 2, 2075 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2077 },
  { 2, 2079 },
  { 2, 2081 },
  { 2, 2083 },
  { 2, 2085 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2087 },
  { 2, 2089 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2091 },
  { 2, 2093 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2095 },
  { 2, 2097 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2099 },
  { 2, 2101 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2103 },
  { 2, 2105 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2107 },
  { 2, 2109 },
  { 2, 2111 },
  { 2, 2113 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2115 },
  { 2, 2117 },
  { 2, 2119 },
  { 2, 2121 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2123 },
  { 2, 2125 },
  { 2, 2127 },
  { 2, 2129 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x30[256] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2135 },
  { 0, 0 },
  { 2, 2137 },
  { 0, 0 },
  { 2, 2139 },
  { 0, 0 },
  { 2, 2141 },
  { 0, 0 },
  { 2, 2143 },
  { 0, 0 },
  { 2, 2145 },
  { 0, 0 },
  { 2, 2147 },
  { 0, 0 },
  { 2, 2149 },
  { 0, 0 },
  { 2, 2151 },
  { 0, 0 },
  { 2, 2153 },
  { 0, 0 },
  { 2, 2155 },
  { 0, 0 },
  { 2, 2157 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2159 },
  { 0, 0 },
  { 2, 2161 },
  { 0, 0 },
  { 2, 2163 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2165 },
  { 2, 2167 },
  { 0, 0 },
  { 2, 2169 },
  { 2, 2171 },
  { 0, 0 },
  { 2, 2173 },
  { 2, 2175 },
  { 0, 0 },
  { 2, 2177 },
  { 2, 2179 },
  { 0, 0 },
  { 2, 2181 },
  { 2, 2183 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2185 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2187 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2189 },
  { 0, 0 },
  { 2, 2191 },
  { 0, 0 },
  { 2, 2193 },
  { 0, 0 },
  { 2, 2195 },
  { 0, 0 },
  { 2, 2197 },
  { 0, 0 },
  { 2, 2199 },
  { 0, 0 },
  { 2, 2201 },
  { 0, 0 },
  { 2, 2203 },
  { 0, 0 },
  { 2, 2205 },
  { 0, 0 },
  { 2, 2207 },
  { 0, 0 },
  { 2, 2209 },
  { 0, 0 },
  { 2, 2211 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2213 },
  { 0, 0 },
  { 2, 2215 },
  { 0, 0 },
  { 2, 2217 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2219 },
  { 2, 2221 },
  { 0, 0 },
  { 2, 2223 },
  { 2, 2225 },
  { 0, 0 },
  { 2, 2227 },
  { 2, 2229 },
  { 0, 0 },
  { 2, 2231 },
  { 2, 2233 },
  { 0, 0 },
  { 2, 2235 },
  { 2, 2237 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2239 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2241 },
  { 2, 2243 },
  { 2, 2245 },
  { 2, 2247 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2249 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0xf9[256] = {
  { 1, 2251 },
  { 1, 2252 },
  { 1, 2253 },
  { 1, 2254 },
  { 1, 2255 },
  { 1, 2256 },
  { 1, 2257 },
  { 1, 2258 },
  { 1, 2259 },
  { 1, 2260 },
  { 1, 2261 },
  { 1, 2262 },
  { 1, 2263 },
  { 1, 2264 },
  { 1, 2265 },
  { 1, 2266 },
  { 1, 2267 },
  { 1, 2268 },
  { 1, 2269 },
  { 1, 2270 },
  { 1, 2271 },
  { 1, 2272 },
  { 1, 2273 },
  { 1, 2274 },
  { 1, 2275 },
  { 1, 2276 },
  { 1, 2277 },
  { 1, 2278 },
  { 1, 2279 },
  { 1, 2280 },
  { 1, 2281 },
  { 1, 2282 },
  { 1, 2283 },
  { 1, 2284 },
  { 1, 2285 },
  { 1, 2286 },
  { 1, 2287 },
  { 1, 2288 },
  { 1, 2289 },
  { 1, 2290 },
  { 1, 2291 },
  { 1, 2292 },
  { 1, 2293 },
  { 1, 2294 },
  { 1, 2295 },
  { 1, 2296 },
  { 1, 2297 },
  { 1, 2298 },
  { 1, 2299 },
  { 1, 2300 },
  { 1, 2301 },
  { 1, 2302 },
  { 1, 2303 },
  { 1, 2304 },
  { 1, 2305 },
  { 1, 2306 },
  { 1, 2307 },
  { 1, 2308 },
  { 1, 2309 },
  { 1, 2310 },
  { 1, 2311 },
  { 1, 2312 },
  { 1, 2313 },
  { 1, 2314 },
  { 1, 2315 },
  { 1, 2316 },
  { 1, 2317 },
  { 1, 2318 },
  { 1, 2319 },
  { 1, 2320 },
  { 1, 2321 },
  { 1, 2322 },
  { 1, 2323 },
  { 1, 2324 },
  { 1, 2325 },
  { 1, 2326 },
  { 1, 2327 },
  { 1, 2328 },
  { 1, 2329 },
  { 1, 2330 },
  { 1, 2331 },
  { 1, 2332 },
  { 1, 2333 },
  { 1, 2334 },
  { 1, 2335 },
  { 1, 2336 },
  { 1, 2337 },
  { 1, 2338 },
  { 1, 2339 },
  { 1, 2340 },
  { 1, 2341 },
  { 1, 2342 },
  { 1, 2343 },
  { 1, 2344 },
  { 1, 2345 },
  { 1, 2346 },
  { 1, 2347 },
  { 1, 2348 },
  { 1, 2349 },
  { 1, 2350 },
  { 1, 2351 },
  { 1, 2352 },
  { 1, 2353 },
  { 1, 2354 },
  { 1, 2355 },
  { 1, 2356 },
  { 1, 2357 },
  { 1, 2358 },
  { 1, 2359 },
  { 1, 2360 },
  { 1, 2361 },
  { 1, 2362 },
  { 1, 2363 },
  { 1, 2364 },
  { 1, 2365 },
  { 1, 2366 },
  { 1, 2367 },
  { 1, 2368 },
  { 1, 2369 },
  { 1, 2370 },
  { 1, 2371 },
  { 1, 2372 },
  { 1, 2373 },
  { 1, 2374 },
  { 1, 2375 },
  { 1, 2376 },
  { 1, 2377 },
  { 1, 2378 },
  { 1, 2379 },
  { 1, 2380 },
  { 1, 2381 },
  { 1, 2382 },
  { 1, 2383 },
  { 1, 2384 },
  { 1, 2385 },
  { 1, 2386 },
  { 1, 2387 },
  { 1, 2388 },
  { 1, 2389 },
  { 1, 2390 },
  { 1, 2391 },
  { 1, 2392 },
  { 1, 2393 },
  { 1, 2394 },
  { 1, 2395 },
  { 1, 2396 },
  { 1, 2397 },
  { 1, 2398 },
  { 1, 2399 },
  { 1, 2400 },
  { 1, 2401 },
  { 1, 2402 },
  { 1, 2403 },
  { 1, 2404 },
  { 1, 2405 },
  { 1, 2406 },
  { 1, 2407 },
  { 1, 2408 },
  { 1, 2409 },
  { 1, 2410 },
  { 1, 2411 },
  { 1, 2412 },
  { 1, 2413 },
  { 1, 2414 },
  { 1, 2415 },
  { 1, 2416 },
  { 1, 2417 },
  { 1, 2418 },
  { 1, 2419 },
  { 1, 2420 },
  { 1, 2421 },
  { 1, 2422 },
  { 1, 2423 },
  { 1, 2424 },
  { 1, 2425 },
  { 1, 2426 },
  { 1, 2427 },
  { 1, 2428 },
  { 1, 2429 },
  { 1, 2430 },
  { 1, 2431 },
  { 1, 2432 },
  { 1, 2433 },
  { 1, 2434 },
  { 1, 2435 },
  { 1, 2436 },
  { 1, 2437 },
  { 1, 2438 },
  { 1, 2439 },
  { 1, 2440 },
  { 1, 2441 },
  { 1, 2442 },
  { 1, 2443 },
  { 1, 2444 },
  { 1, 2445 },
  { 1, 2446 },
  { 1, 2447 },
  { 1, 2448 },
  { 1, 2449 },
  { 1, 2450 },
  { 1, 2451 },
  { 1, 2452 },
  { 1, 2453 },
  { 1, 2454 },
  { 1, 2455 },
  { 1, 2456 },
  { 1, 2457 },
  { 1, 2458 },
  { 1, 2459 },
  { 1, 2460 },
  { 1, 2461 },
  { 1, 2462 },
  { 1, 2463 },
  { 1, 2464 },
  { 1, 2465 },
  { 1, 2466 },
  { 1, 2467 },
  { 1, 2468 },
  { 1, 2469 },
  { 1, 2470 },
  { 1, 2471 },
  { 1, 2472 },
  { 1, 2473 },
  { 1, 2474 },
  { 1, 2475 },
  { 1, 2476 },
  { 1, 2477 },
  { 1, 2478 },
  { 1, 2479 },
  { 1, 2480 },
  { 1, 2481 },
  { 1, 2482 },
  { 1, 2483 },
  { 1, 2484 },
  { 1, 2485 },
  { 1, 2486 },
  { 1, 2487 },
  { 1, 2488 },
  { 1, 2489 },
  { 1, 2490 },
  { 1, 2491 },
  { 1, 2492 },
  { 1, 2493 },
  { 1, 2494 },
  { 1, 2495 },
  { 1, 2496 },
  { 1, 2497 },
  { 1, 2498 },
  { 1, 2499 },
  { 1, 2500 },
  { 1, 2501 },
  { 1, 2502 },
  { 1, 2503 },
  { 1, 2504 },
  { 1, 2505 },
  { 1, 2506 },
};

static decomp_block_t unigen_decomp_block_0xfa[256] = {
  { 1, 2507 },
  { 1, 2508 },
  { 1, 2509 },
  { 1, 2510 },
  { 1, 2511 },
  { 1, 2512 },
  { 1, 2513 },
  { 1, 2514 },
  { 1, 2515 },
  { 1, 2516 },
  { 1, 2517 },
  { 1, 2518 },
  { 1, 2519 },
  { 1, 2520 },
  { 0, 0 },
  { 0, 0 },
  { 1, 2521 },
  { 0, 0 },
  { 1, 2522 },
  { 0, 0 },
  { 0, 0 },
  { 1, 2523 },
  { 1, 2524 },
  { 1, 2525 },
  { 1, 2526 },
  { 1, 2527 },
  { 1, 2528 },
  { 1, 2529 },
  { 1, 2530 },
  { 1, 2531 },
  { 1, 2532 },
  { 0, 0 },
  { 1, 2533 },
  { 0, 0 },
  { 1, 2534 },
  { 0, 0 },
  { 0, 0 },
  { 1, 2535 },
  { 1, 2536 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 1, 2537 },
  { 1, 2538 },
  { 1, 2539 },
  { 1, 2540 },
  { 0, 0 },
  { 0, 0 },
  { 1, 2541 },
  { 1, 2542 },
  { 1, 2543 },
  { 1, 2544 },
  { 1, 2545 },
  { 1, 2546 },
  { 1, 2547 },
  { 1, 2548 },
  { 1, 2549 },
  { 1, 2550 },
  { 1, 2551 },
  { 1, 2552 },
  { 1, 2553 },
  { 1, 2554 },
  { 1, 2555 },
  { 1, 2556 },
  { 1, 2557 },
  { 1, 2558 },
  { 1, 2559 },
  { 1, 2560 },
  { 1, 2561 },
  { 1, 2562 },
  { 1, 2563 },
  { 1, 2564 },
  { 1, 2565 },
  { 1, 2566 },
  { 1, 2567 },
  { 1, 2568 },
  { 1, 2569 },
  { 1, 2570 },
  { 1, 2571 },
  { 1, 2572 },
  { 1, 2573 },
  { 1, 2574 },
  { 1, 2575 },
  { 1, 2576 },
  { 1, 2577 },
  { 1, 2578 },
  { 1, 2579 },
  { 1, 2580 },
  { 1, 2581 },
  { 1, 2582 },
  { 1, 2583 },
  { 1, 2584 },
  { 1, 2585 },
  { 1, 2586 },
  { 1, 2587 },
  { 1, 2588 },
  { 1, 2589 },
  { 1, 2590 },
  { 1, 2591 },
  { 1, 2592 },
  { 1, 2593 },
  { 1, 2594 },
  { 1, 2595 },
  { 1, 2596 },
  { 1, 2597 },
  { 1, 2598 },
  { 1, 2599 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0xfb[256] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2600 },
  { 0, 0 },
  { 2, 2602 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 2, 2604 },
  { 2, 2606 },
  { 3, 2608 },
  { 3, 2611 },
  { 2, 2614 },
  { 2, 2616 },
  { 2, 2618 },
  { 2, 2620 },
  { 2, 2622 },
  { 2, 2624 },
  { 2, 2626 },
  { 2, 2628 },
  { 2, 2630 },
  { 0, 0 },
  { 2, 2632 },
  { 2, 2634 },
  { 2, 2636 },
  { 2, 2638 },
  { 2, 2640 },
  { 0, 0 },
  { 2, 2642 },
  { 0, 0 },
  { 2, 2644 },
  { 2, 2646 },
  { 0, 0 },
  { 2, 2648 },
  { 2, 2650 },
  { 0, 0 },
  { 2, 2652 },
  { 2, 2654 },
  { 2, 2656 },
  { 2, 2658 },
  { 2, 2660 },
  { 2, 2662 },
  { 2, 2664 },
  { 2, 2666 },
  { 2, 2668 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static decomp_block_t unigen_decomp_block_0x2f8[256] = {
  { 1, 2705 },
  { 1, 2706 },
  { 1, 2707 },
  { 1, 2708 },
  { 1, 2709 },
  { 1, 2710 },
  { 1, 2711 },
  { 1, 2712 },
  { 1, 2713 },
  { 1, 2714 },
  { 1, 2715 },
  { 1, 2716 },
  { 1, 2717 },
  { 1, 2718 },
  { 1, 2719 },
  { 1, 2720 },
  { 1, 2721 },
  { 1, 2722 },
  { 1, 2723 },
  { 1, 2724 },
  { 1, 2725 },
  { 1, 2726 },
  { 1, 2727 },
  { 1, 2728 },
  { 1, 2729 },
  { 1, 2730 },
  { 1, 2731 },
  { 1, 2732 },
  { 1, 2733 },
  { 1, 2734 },
  { 1, 2735 },
  { 1, 2736 },
  { 1, 2737 },
  { 1, 2738 },
  { 1, 2739 },
  { 1, 2740 },
  { 1, 2741 },
  { 1, 2742 },
  { 1, 2743 },
  { 1, 2744 },
  { 1, 2745 },
  { 1, 2746 },
  { 1, 2747 },
  { 1, 2748 },
  { 1, 2749 },
  { 1, 2750 },
  { 1, 2751 },
  { 1, 2752 },
  { 1, 2753 },
  { 1, 2754 },
  { 1, 2755 },
  { 1, 2756 },
  { 1, 2757 },
  { 1, 2758 },
  { 1, 2759 },
  { 1, 2760 },
  { 1, 2761 },
  { 1, 2762 },
  { 1, 2763 },
  { 1, 2764 },
  { 1, 2765 },
  { 1, 2766 },
  { 1, 2767 },
  { 1, 2768 },
  { 1, 2769 },
  { 1, 2770 },
  { 1, 2771 },
  { 1, 2772 },
  { 1, 2773 },
  { 1, 2774 },
  { 1, 2775 },
  { 1, 2776 },
  { 1, 2777 },
  { 1, 2778 },
  { 1, 2779 },
  { 1, 2780 },
  { 1, 2781 },
  { 1, 2782 },
  { 1, 2783 },
  { 1, 2784 },
  { 1, 2785 },
  { 1, 2786 },
  { 1, 2787 },
  { 1, 2788 },
  { 1, 2789 },
  { 1, 2790 },
  { 1, 2791 },
  { 1, 2792 },
  { 1, 2793 },
  { 1, 2794 },
  { 1, 2795 },
  { 1, 2796 },
  { 1, 2797 },
  { 1, 2798 },
  { 1, 2799 },
  { 1, 2800 },
  { 1, 2801 },
  { 1, 2802 },
  { 1, 2803 },
  { 1, 2804 },
  { 1, 2805 },
  { 1, 2806 },
  { 1, 2807 },
  { 1, 2808 },
  { 1, 2809 },
  { 1, 2810 },
  { 1, 2811 },
  { 1, 2812 },
  { 1, 2813 },
  { 1, 2814 },
  { 1, 2815 },
  { 1, 2816 },
  { 1, 2817 },
  { 1, 2818 },
  { 1, 2819 },
  { 1, 2820 },
  { 1, 2821 },
  { 1, 2822 },
  { 1, 2823 },
  { 1, 2824 },
  { 1, 2825 },
  { 1, 2826 },
  { 1, 2827 },
  { 1, 2828 },
  { 1, 2829 },
  { 1, 2830 },
  { 1, 2831 },
  { 1, 2832 },
  { 1, 2833 },
  { 1, 2834 },
  { 1, 2835 },
  { 1, 2836 },
  { 1, 2837 },
  { 1, 2838 },
  { 1, 2839 },
  { 1, 2840 },
  { 1, 2841 },
  { 1, 2842 },
  { 1, 2843 },
  { 1, 2844 },
  { 1, 2845 },
  { 1, 2846 },
  { 1, 2847 },
  { 1, 2848 },
  { 1, 2849 },
  { 1, 2850 },
  { 1, 2851 },
  { 1, 2852 },
  { 1, 2853 },
  { 1, 2854 },
  { 1, 2855 },
  { 1, 2856 },
  { 1, 2857 },
  { 1, 2858 },
  { 1, 2859 },
  { 1, 2860 },
  { 1, 2861 },
  { 1, 2862 },
  { 1, 2863 },
  { 1, 2864 },
  { 1, 2865 },
  { 1, 2866 },
  { 1, 2867 },
  { 1, 2868 },
  { 1, 2869 },
  { 1, 2870 },
  { 1, 2871 },
  { 1, 2872 },
  { 1, 2873 },
  { 1, 2874 },
  { 1, 2875 },
  { 1, 2876 },
  { 1, 2877 },
  { 1, 2878 },
  { 1, 2879 },
  { 1, 2880 },
  { 1, 2881 },
  { 1, 2882 },
  { 1, 2883 },
  { 1, 2884 },
  { 1, 2885 },
  { 1, 2886 },
  { 1, 2887 },
  { 1, 2888 },
  { 1, 2889 },
  { 1, 2890 },
  { 1, 2891 },
  { 1, 2892 },
  { 1, 2893 },
  { 1, 2894 },
  { 1, 2895 },
  { 1, 2896 },
  { 1, 2897 },
  { 1, 2898 },
  { 1, 2899 },
  { 1, 2900 },
  { 1, 2901 },
  { 1, 2902 },
  { 1, 2903 },
  { 1, 2904 },
  { 1, 2905 },
  { 1, 2906 },
  { 1, 2907 },
  { 1, 2908 },
  { 1, 2909 },
  { 1, 2910 },
  { 1, 2911 },
  { 1, 2912 },
  { 1, 2913 },
  { 1, 2914 },
  { 1, 2915 },
  { 1, 2916 },
  { 1, 2917 },
  { 1, 2918 },
  { 1, 2919 },
  { 1, 2920 },
  { 1, 2921 },
  { 1, 2922 },
  { 1, 2923 },
  { 1, 2924 },
  { 1, 2925 },
  { 1, 2926 },
  { 1, 2927 },
  { 1, 2928 },
  { 1, 2929 },
  { 1, 2930 },
  { 1, 2931 },
  { 1, 2932 },
  { 1, 2933 },
  { 1, 2934 },
  { 1, 2935 },
  { 1, 2936 },
  { 1, 2937 },
  { 1, 2938 },
  { 1, 2939 },
  { 1, 2940 },
  { 1, 2941 },
  { 1, 2942 },
  { 1, 2943 },
  { 1, 2944 },
  { 1, 2945 },
  { 1, 2946 },
  { 1, 2947 },
  { 1, 2948 },
  { 1, 2949 },
  { 1, 2950 },
  { 1, 2951 },
  { 1, 2952 },
  { 1, 2953 },
  { 1, 2954 },
  { 1, 2955 },
  { 1, 2956 },
  { 1, 2957 },
  { 1, 2958 },
  { 1, 2959 },
  { 1, 2960 },
};

static decomp_block_t unigen_decomp_block_0x2f9[256] = {
  { 1, 2961 },
  { 1, 2962 },
  { 1, 2963 },
  { 1, 2964 },
  { 1, 2965 },
  { 1, 2966 },
  { 1, 2967 },
  { 1, 2968 },
  { 1, 2969 },
  { 1, 2970 },
  { 1, 2971 },
  { 1, 2972 },
  { 1, 2973 },
  { 1, 2974 },
  { 1, 2975 },
  { 1, 2976 },
  { 1, 2977 },
  { 1, 2978 },
  { 1, 2979 },
  { 1, 2980 },
  { 1, 2981 },
  { 1, 2982 },
  { 1, 2983 },
  { 1, 2984 },
  { 1, 2985 },
  { 1, 2986 },
  { 1, 2987 },
  { 1, 2988 },
  { 1, 2989 },
  { 1, 2990 },
  { 1, 2991 },
  { 1, 2992 },
  { 1, 2993 },
  { 1, 2994 },
  { 1, 2995 },
  { 1, 2996 },
  { 1, 2997 },
  { 1, 2998 },
  { 1, 2999 },
  { 1, 3000 },
  { 1, 3001 },
  { 1, 3002 },
  { 1, 3003 },
  { 1, 3004 },
  { 1, 3005 },
  { 1, 3006 },
  { 1, 3007 },
  { 1, 3008 },
  { 1, 3009 },
  { 1, 3010 },
  { 1, 3011 },
  { 1, 3012 },
  { 1, 3013 },
  { 1, 3014 },
  { 1, 3015 },
  { 1, 3016 },
  { 1, 3017 },
  { 1, 3018 },
  { 1, 3019 },
  { 1, 3020 },
  { 1, 3021 },
  { 1, 3022 },
  { 1, 3023 },
  { 1, 3024 },
  { 1, 3025 },
  { 1, 3026 },
  { 1, 3027 },
  { 1, 3028 },
  { 1, 3029 },
  { 1, 3030 },
  { 1, 3031 },
  { 1, 3032 },
  { 1, 3033 },
  { 1, 3034 },
  { 1, 3035 },
  { 1, 3036 },
  { 1, 3037 },
  { 1, 3038 },
  { 1, 3039 },
  { 1, 3040 },
  { 1, 3041 },
  { 1, 3042 },
  { 1, 3043 },
  { 1, 3044 },
  { 1, 3045 },
  { 1, 3046 },
  { 1, 3047 },
  { 1, 3048 },
  { 1, 3049 },
  { 1, 3050 },
  { 1, 3051 },
  { 1, 3052 },
  { 1, 3053 },
  { 1, 3054 },
  { 1, 3055 },
  { 1, 3056 },
  { 1, 3057 },
  { 1, 3058 },
  { 1, 3059 },
  { 1, 3060 },
  { 1, 3061 },
  { 1, 3062 },
  { 1, 3063 },
  { 1, 3064 },
  { 1, 3065 },
  { 1, 3066 },
  { 1, 3067 },
  { 1, 3068 },
  { 1, 3069 },
  { 1, 3070 },
  { 1, 3071 },
  { 1, 3072 },
  { 1, 3073 },
  { 1, 3074 },
  { 1, 3075 },
  { 1, 3076 },
  { 1, 3077 },
  { 1, 3078 },
  { 1, 3079 },
  { 1, 3080 },
  { 1, 3081 },
  { 1, 3082 },
  { 1, 3083 },
  { 1, 3084 },
  { 1, 3085 },
  { 1, 3086 },
  { 1, 3087 },
  { 1, 3088 },
  { 1, 3089 },
  { 1, 3090 },
  { 1, 3091 },
  { 1, 3092 },
  { 1, 3093 },
  { 1, 3094 },
  { 1, 3095 },
  { 1, 3096 },
  { 1, 3097 },
  { 1, 3098 },
  { 1, 3099 },
  { 1, 3100 },
  { 1, 3101 },
  { 1, 3102 },
  { 1, 3103 },
  { 1, 3104 },
  { 1, 3105 },
  { 1, 3106 },
  { 1, 3107 },
  { 1, 3108 },
  { 1, 3109 },
  { 1, 3110 },
  { 1, 3111 },
  { 1, 3112 },
  { 1, 3113 },
  { 1, 3114 },
  { 1, 3115 },
  { 1, 3116 },
  { 1, 3117 },
  { 1, 3118 },
  { 1, 3119 },
  { 1, 3120 },
  { 1, 3121 },
  { 1, 3122 },
  { 1, 3123 },
  { 1, 3124 },
  { 1, 3125 },
  { 1, 3126 },
  { 1, 3127 },
  { 1, 3128 },
  { 1, 3129 },
  { 1, 3130 },
  { 1, 3131 },
  { 1, 3132 },
  { 1, 3133 },
  { 1, 3134 },
  { 1, 3135 },
  { 1, 3136 },
  { 1, 3137 },
  { 1, 3138 },
  { 1, 3139 },
  { 1, 3140 },
  { 1, 3141 },
  { 1, 3142 },
  { 1, 3143 },
  { 1, 3144 },
  { 1, 3145 },
  { 1, 3146 },
  { 1, 3147 },
  { 1, 3148 },
  { 1, 3149 },
  { 1, 3150 },
  { 1, 3151 },
  { 1, 3152 },
  { 1, 3153 },
  { 1, 3154 },
  { 1, 3155 },
  { 1, 3156 },
  { 1, 3157 },
  { 1, 3158 },
  { 1, 3159 },
  { 1, 3160 },
  { 1, 3161 },
  { 1, 3162 },
  { 1, 3163 },
  { 1, 3164 },
  { 1, 3165 },
  { 1, 3166 },
  { 1, 3167 },
  { 1, 3168 },
  { 1, 3169 },
  { 1, 3170 },
  { 1, 3171 },
  { 1, 3172 },
  { 1, 3173 },
  { 1, 3174 },
  { 1, 3175 },
  { 1, 3176 },
  { 1, 3177 },
  { 1, 3178 },
  { 1, 3179 },
  { 1, 3180 },
  { 1, 3181 },
  { 1, 3182 },
  { 1, 3183 },
  { 1, 3184 },
  { 1, 3185 },
  { 1, 3186 },
  { 1, 3187 },
  { 1, 3188 },
  { 1, 3189 },
  { 1, 3190 },
  { 1, 3191 },
  { 1, 3192 },
  { 1, 3193 },
  { 1, 3194 },
  { 1, 3195 },
  { 1, 3196 },
  { 1, 3197 },
  { 1, 3198 },
  { 1, 3199 },
  { 1, 3200 },
  { 1, 3201 },
  { 1, 3202 },
  { 1, 3203 },
  { 1, 3204 },
  { 1, 3205 },
  { 1, 3206 },
  { 1, 3207 },
  { 1, 3208 },
  { 1, 3209 },
  { 1, 3210 },
  { 1, 3211 },
  { 1, 3212 },
  { 1, 3213 },
  { 1, 3214 },
  { 1, 3215 },
  { 1, 3216 },
};

static decomp_block_t unigen_decomp_block_0x2fa[256] = {
  { 1, 3217 },
  { 1, 3218 },
  { 1, 3219 },
  { 1, 3220 },
  { 1, 3221 },
  { 1, 3222 },
  { 1, 3223 },
  { 1, 3224 },
  { 1, 3225 },
  { 1, 3226 },
  { 1, 3227 },
  { 1, 3228 },
  { 1, 3229 },
  { 1, 3230 },
  { 1, 3231 },
  { 1, 3232 },
  { 1, 3233 },
  { 1, 3234 },
  { 1, 3235 },
  { 1, 3236 },
  { 1, 3237 },
  { 1, 3238 },
  { 1, 3239 },
  { 1, 3240 },
  { 1, 3241 },
  { 1, 3242 },
  { 1, 3243 },
  { 1, 3244 },
  { 1, 3245 },
  { 1, 3246 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

static void get_decomp_block(glui32 ch, decomp_block_t **blockptr)
{
  switch (ch >> 8)
  {
  case 0x0:
    *blockptr = unigen_decomp_block_0x0;
    break;
  case 0x1:
    *blockptr = unigen_decomp_block_0x1;
    break;
  case 0x2:
    *blockptr = unigen_decomp_block_0x2;
    break;
  case 0x3:
    *blockptr = unigen_decomp_block_0x3;
    break;
  case 0x4:
    *blockptr = unigen_decomp_block_0x4;
    break;
  case 0x1e:
    *blockptr = unigen_decomp_block_0x1e;
    break;
  case 0x1f:
    *blockptr = unigen_decomp_block_0x1f;
    break;
  case 0x22:
    *blockptr = unigen_decomp_block_0x22;
    break;
  case 0x30:
    *blockptr = unigen_decomp_block_0x30;
    break;
  case 0xf9:
    *blockptr = unigen_decomp_block_0xf9;
    break;
  case 0xfa:
    *blockptr = unigen_decomp_block_0xfa;
    break;
  case 0xfb:
    *blockptr = unigen_decomp_block_0xfb;
    break;
  case 0x2f8:
    *blockptr = unigen_decomp_block_0x2f8;
    break;
  case 0x2f9:
    *blockptr = unigen_decomp_block_0x2f9;
    break;
  case 0x2fa:
    *blockptr = unigen_decomp_block_0x2fa;
    break;
  default:
    *blockptr = NULL;
    break;
  }
}

static void get_decomp_special(glui32 ch, glui32 *countptr, glui32 *posptr)
{
  switch (ch)
  {
  case 0x622:
    *countptr = 2; *posptr = 686;
    break;
  case 0x623:
    *countptr = 2; *posptr = 688;
    break;
  case 0x624:
    *countptr = 2; *posptr = 690;
    break;
  case 0x625:
    *countptr = 2; *posptr = 692;
    break;
  case 0x626:
    *countptr = 2; *posptr = 694;
    break;
  case 0x6c0:
    *countptr = 2; *posptr = 696;
    break;
  case 0x6c2:
    *countptr = 2; *posptr = 698;
    break;
  case 0x6d3:
    *countptr = 2; *posptr = 700;
    break;
  case 0x929:
    *countptr = 2; *posptr = 702;
    break;
  case 0x931:
    *countptr = 2; *posptr = 704;
    break;
  case 0x934:
    *countptr = 2; *posptr = 706;
    break;
  case 0x958:
    *countptr = 2; *posptr = 708;
    break;
  case 0x959:
    *countptr = 2; *posptr = 710;
    break;
  case 0x95a:
    *countptr = 2; *posptr = 712;
    break;
  case 0x95b:
    *countptr = 2; *posptr = 714;
    break;
  case 0x95c:
    *countptr = 2; *posptr = 716;
    break;
  case 0x95d:
    *countptr = 2; *posptr = 718;
    break;
  case 0x95e:
    *countptr = 2; *posptr = 720;
    break;
  case 0x95f:
    *countptr = 2; *posptr = 722;
    break;
  case 0x9cb:
    *countptr = 2; *posptr = 724;
    break;
  case 0x9cc:
    *countptr = 2; *posptr = 726;
    break;
  case 0x9dc:
    *countptr = 2; *posptr = 728;
    break;
  case 0x9dd:
    *countptr = 2; *posptr = 730;
    break;
  case 0x9df:
    *countptr = 2; *posptr = 732;
    break;
  case 0xa33:
    *countptr = 2; *posptr = 734;
    break;
  case 0xa36:
    *countptr = 2; *posptr = 736;
    break;
  case 0xa59:
    *countptr = 2; *posptr = 738;
    break;
  case 0xa5a:
    *countptr = 2; *posptr = 740;
    break;
  case 0xa5b:
    *countptr = 2; *posptr = 742;
    break;
  case 0xa5e:
    *countptr = 2; *posptr = 744;
    break;
  case 0xb48:
    *countptr = 2; *posptr = 746;
    break;
  case 0xb4b:
    *countptr = 2; *posptr = 748;
    break;
  case 0xb4c:
    *countptr = 2; *posptr = 750;
    break;
  case 0xb5c:
    *countptr = 2; *posptr = 752;
    break;
  case 0xb5d:
    *countptr = 2; *posptr = 754;
    break;
  case 0xb94:
    *countptr = 2; *posptr = 756;
    break;
  case 0xbca:
    *countptr = 2; *posptr = 758;
    break;
  case 0xbcb:
    *countptr = 2; *posptr = 760;
    break;
  case 0xbcc:
    *countptr = 2; *posptr = 762;
    break;
  case 0xc48:
    *countptr = 2; *posptr = 764;
    break;
  case 0xcc0:
    *countptr = 2; *posptr = 766;
    break;
  case 0xcc7:
    *countptr = 2; *posptr = 768;
    break;
  case 0xcc8:
    *countptr = 2; *posptr = 770;
    break;
  case 0xcca:
    *countptr = 2; *posptr = 772;
    break;
  case 0xccb:
    *countptr = 3; *posptr = 774;
    break;
  case 0xd4a:
    *countptr = 2; *posptr = 777;
    break;
  case 0xd4b:
    *countptr = 2; *posptr = 779;
    break;
  case 0xd4c:
    *countptr = 2; *posptr = 781;
    break;
  case 0xdda:
    *countptr = 2; *posptr = 783;
    break;
  case 0xddc:
    *countptr = 2; *posptr = 785;
    break;
  case 0xddd:
    *countptr = 3; *posptr = 787;
    break;
  case 0xdde:
    *countptr = 2; *posptr = 790;
    break;
  case 0xf43:
    *countptr = 2; *posptr = 792;
    break;
  case 0xf4d:
    *countptr = 2; *posptr = 794;
    break;
  case 0xf52:
    *countptr = 2; *posptr = 796;
    break;
  case 0xf57:
    *countptr = 2; *posptr = 798;
    break;
  case 0xf5c:
    *countptr = 2; *posptr = 800;
    break;
  case 0xf69:
    *countptr = 2; *posptr = 802;
    break;
  case 0xf73:
    *countptr = 2; *posptr = 804;
    break;
  case 0xf75:
    *countptr = 2; *posptr = 806;
    break;
  case 0xf76:
    *countptr = 2; *posptr = 808;
    break;
  case 0xf78:
    *countptr = 2; *posptr = 810;
    break;
  case 0xf81:
    *countptr = 2; *posptr = 812;
    break;
  case 0xf93:
    *countptr = 2; *posptr = 814;
    break;
  case 0xf9d:
    *countptr = 2; *posptr = 816;
    break;
  case 0xfa2:
    *countptr = 2; *posptr = 818;
    break;
  case 0xfa7:
    *countptr = 2; *posptr = 820;
    break;
  case 0xfac:
    *countptr = 2; *posptr = 822;
    break;
  case 0xfb9:
    *countptr = 2; *posptr = 824;
    break;
  case 0x1026:
    *countptr = 2; *posptr = 826;
    break;
  case 0x2000:
    *countptr = 1; *posptr = 2037;
    break;
  case 0x2001:
    *countptr = 1; *posptr = 2038;
    break;
  case 0x2126:
    *countptr = 1; *posptr = 2039;
    break;
  case 0x212a:
    *countptr = 1; *posptr = 2040;
    break;
  case 0x212b:
    *countptr = 2; *posptr = 2041;
    break;
  case 0x219a:
    *countptr = 2; *posptr = 2043;
    break;
  case 0x219b:
    *countptr = 2; *posptr = 2045;
    break;
  case 0x21ae:
    *countptr = 2; *posptr = 2047;
    break;
  case 0x21cd:
    *countptr = 2; *posptr = 2049;
    break;
  case 0x21ce:
    *countptr = 2; *posptr = 2051;
    break;
  case 0x21cf:
    *countptr = 2; *posptr = 2053;
    break;
  case 0x2329:
    *countptr = 1; *posptr = 2131;
    break;
  case 0x232a:
    *countptr = 1; *posptr = 2132;
    break;
  case 0x2adc:
    *countptr = 2; *posptr = 2133;
    break;
  case 0x1d15e:
    *countptr = 2; *posptr = 2670;
    break;
  case 0x1d15f:
    *countptr = 2; *posptr = 2672;
    break;
  case 0x1d160:
    *countptr = 3; *posptr = 2674;
    break;
  case 0x1d161:
    *countptr = 3; *posptr = 2677;
    break;
  case 0x1d162:
    *countptr = 3; *posptr = 2680;
    break;
  case 0x1d163:
    *countptr = 3; *posptr = 2683;
    break;
  case 0x1d164:
    *countptr = 3; *posptr = 2686;
    break;
  case 0x1d1bb:
    *countptr = 2; *posptr = 2689;
    break;
  case 0x1d1bc:
    *countptr = 2; *posptr = 2691;
    break;
  case 0x1d1bd:
    *countptr = 3; *posptr = 2693;
    break;
  case 0x1d1be:
    *countptr = 3; *posptr = 2696;
    break;
  case 0x1d1bf:
    *countptr = 3; *posptr = 2699;
    break;
  case 0x1d1c0:
    *countptr = 3; *posptr = 2702;
    break;
  default:
    *countptr = 0;
    break;
  }
}

glui32 *buffer_canon_decompose(glui32 *buf, glui32 *numcharsref)
{
  /* The algorithm for the canonical decomposition of a string: For
     each character, look up the decomposition in the decomp table.
     Append the decomposition to the buffer. Finally, sort every
     substring of the buffer which is made up of combining
     characters (characters with a nonzero combining class). */

  glui32 numchars = *numcharsref;
  glui32 destsize = numchars * 2 + 16;
  glui32 *dest = (glui32 *)malloc(destsize * sizeof(glui32));
  glui32 destlen = 0;
  glui32 ix, jx;
  int anycombining = 0;

  if (!dest)
    return NULL;

  for (ix=0; ix < numchars; ix++)
  {
    glui32 ch = buf[ix];
    decomp_block_t *block;
    glui32 count, pos;

    if (combining_class(ch))
      anycombining = 1;

    get_decomp_block(ch, &block);
    if (block)
    {
      block += (ch & 0xFF);
      count = (*block)[0];
      pos = (*block)[1];
    }
    else
      get_decomp_special(ch, &count, &pos);

    if (!count)
    {
      if (destlen >= destsize)
      {
        destsize = destsize * 2;
        dest = (glui32 *)realloc(dest, destsize * sizeof(glui32));
        if (!dest)
          return NULL;
      }
      dest[destlen] = ch;
      destlen++;
      continue;
    }

    anycombining = 1;

    if (destlen+count >= destsize)
    {
      destsize = destsize * 2 + count;
      dest = (glui32 *)realloc(dest, destsize * sizeof(glui32));
      if (!dest)
        return NULL;
    }
    for (jx=0; jx<count; jx++)
    {
      dest[destlen] = unigen_decomp_data[pos+jx];
      destlen++;
    }
  }

  if (anycombining)
  {
    glui32 grpstart, grpend, kx;
    ix = 0;
    while (ix < destlen)
    {
      if (!combining_class(dest[ix]))
      {
        ix++;
        continue;
      }
      if (ix >= destlen)
        break;
      grpstart = ix;
      while (ix < destlen && combining_class(dest[ix])) 
        ix++;
      grpend = ix;
      if (grpend - grpstart >= 2)
      {
        for (jx = grpend-1; jx > grpstart; jx--)
        {
          for (kx = grpstart; kx < jx; kx++)
          {
            if (combining_class(dest[kx]) > combining_class(dest[kx+1]))
            {
              glui32 tmp = dest[kx];
              dest[kx] = dest[kx+1];
              dest[kx+1] = tmp;
            }
          }
        }
      }
    }
  }

  *numcharsref = destlen;
  return dest;
}

static glui32 check_composition(glui32 ch1, glui32 ch2)
{
  switch ((glui32)(ch1) >> 8) {
    case 0:
      switch (ch1) {
        case 60:
          switch (ch2) {
            case 824: return 8814;
          }
          return 0;
        case 61:
          switch (ch2) {
            case 824: return 8800;
          }
          return 0;
        case 62:
          switch (ch2) {
            case 824: return 8815;
          }
          return 0;
        case 65:
          switch (ch2) {
            case 768: return 192;
            case 769: return 193;
            case 770: return 194;
            case 771: return 195;
            case 772: return 256;
            case 774: return 258;
            case 775: return 550;
            case 776: return 196;
            case 777: return 7842;
            case 778: return 197;
            case 780: return 461;
            case 783: return 512;
            case 785: return 514;
            case 803: return 7840;
            case 805: return 7680;
            case 808: return 260;
          }
          return 0;
        case 66:
          switch (ch2) {
            case 775: return 7682;
            case 803: return 7684;
            case 817: return 7686;
          }
          return 0;
        case 67:
          switch (ch2) {
            case 769: return 262;
            case 770: return 264;
            case 775: return 266;
            case 780: return 268;
            case 807: return 199;
          }
          return 0;
        case 68:
          switch (ch2) {
            case 775: return 7690;
            case 780: return 270;
            case 803: return 7692;
            case 807: return 7696;
            case 813: return 7698;
            case 817: return 7694;
          }
          return 0;
        case 69:
          switch (ch2) {
            case 768: return 200;
            case 769: return 201;
            case 770: return 202;
            case 771: return 7868;
            case 772: return 274;
            case 774: return 276;
            case 775: return 278;
            case 776: return 203;
            case 777: return 7866;
            case 780: return 282;
            case 783: return 516;
            case 785: return 518;
            case 803: return 7864;
            case 807: return 552;
            case 808: return 280;
            case 813: return 7704;
            case 816: return 7706;
          }
          return 0;
        case 70:
          switch (ch2) {
            case 775: return 7710;
          }
          return 0;
        case 71:
          switch (ch2) {
            case 769: return 500;
            case 770: return 284;
            case 772: return 7712;
            case 774: return 286;
            case 775: return 288;
            case 780: return 486;
            case 807: return 290;
          }
          return 0;
        case 72:
          switch (ch2) {
            case 770: return 292;
            case 775: return 7714;
            case 776: return 7718;
            case 780: return 542;
            case 803: return 7716;
            case 807: return 7720;
            case 814: return 7722;
          }
          return 0;
        case 73:
          switch (ch2) {
            case 768: return 204;
            case 769: return 205;
            case 770: return 206;
            case 771: return 296;
            case 772: return 298;
            case 774: return 300;
            case 775: return 304;
            case 776: return 207;
            case 777: return 7880;
            case 780: return 463;
            case 783: return 520;
            case 785: return 522;
            case 803: return 7882;
            case 808: return 302;
            case 816: return 7724;
          }
          return 0;
        case 74:
          switch (ch2) {
            case 770: return 308;
          }
          return 0;
        case 75:
          switch (ch2) {
            case 769: return 7728;
            case 780: return 488;
            case 803: return 7730;
            case 807: return 310;
            case 817: return 7732;
          }
          return 0;
        case 76:
          switch (ch2) {
            case 769: return 313;
            case 780: return 317;
            case 803: return 7734;
            case 807: return 315;
            case 813: return 7740;
            case 817: return 7738;
          }
          return 0;
        case 77:
          switch (ch2) {
            case 769: return 7742;
            case 775: return 7744;
            case 803: return 7746;
          }
          return 0;
        case 78:
          switch (ch2) {
            case 768: return 504;
            case 769: return 323;
            case 771: return 209;
            case 775: return 7748;
            case 780: return 327;
            case 803: return 7750;
            case 807: return 325;
            case 813: return 7754;
            case 817: return 7752;
          }
          return 0;
        case 79:
          switch (ch2) {
            case 768: return 210;
            case 769: return 211;
            case 770: return 212;
            case 771: return 213;
            case 772: return 332;
            case 774: return 334;
            case 775: return 558;
            case 776: return 214;
            case 777: return 7886;
            case 779: return 336;
            case 780: return 465;
            case 783: return 524;
            case 785: return 526;
            case 795: return 416;
            case 803: return 7884;
            case 808: return 490;
          }
          return 0;
        case 80:
          switch (ch2) {
            case 769: return 7764;
            case 775: return 7766;
          }
          return 0;
        case 82:
          switch (ch2) {
            case 769: return 340;
            case 775: return 7768;
            case 780: return 344;
            case 783: return 528;
            case 785: return 530;
            case 803: return 7770;
            case 807: return 342;
            case 817: return 7774;
          }
          return 0;
        case 83:
          switch (ch2) {
            case 769: return 346;
            case 770: return 348;
            case 775: return 7776;
            case 780: return 352;
            case 803: return 7778;
            case 806: return 536;
            case 807: return 350;
          }
          return 0;
        case 84:
          switch (ch2) {
            case 775: return 7786;
            case 780: return 356;
            case 803: return 7788;
            case 806: return 538;
            case 807: return 354;
            case 813: return 7792;
            case 817: return 7790;
          }
          return 0;
        case 85:
          switch (ch2) {
            case 768: return 217;
            case 769: return 218;
            case 770: return 219;
            case 771: return 360;
            case 772: return 362;
            case 774: return 364;
            case 776: return 220;
            case 777: return 7910;
            case 778: return 366;
            case 779: return 368;
            case 780: return 467;
            case 783: return 532;
            case 785: return 534;
            case 795: return 431;
            case 803: return 7908;
            case 804: return 7794;
            case 808: return 370;
            case 813: return 7798;
            case 816: return 7796;
          }
          return 0;
        case 86:
          switch (ch2) {
            case 771: return 7804;
            case 803: return 7806;
          }
          return 0;
        case 87:
          switch (ch2) {
            case 768: return 7808;
            case 769: return 7810;
            case 770: return 372;
            case 775: return 7814;
            case 776: return 7812;
            case 803: return 7816;
          }
          return 0;
        case 88:
          switch (ch2) {
            case 775: return 7818;
            case 776: return 7820;
          }
          return 0;
        case 89:
          switch (ch2) {
            case 768: return 7922;
            case 769: return 221;
            case 770: return 374;
            case 771: return 7928;
            case 772: return 562;
            case 775: return 7822;
            case 776: return 376;
            case 777: return 7926;
            case 803: return 7924;
          }
          return 0;
        case 90:
          switch (ch2) {
            case 769: return 377;
            case 770: return 7824;
            case 775: return 379;
            case 780: return 381;
            case 803: return 7826;
            case 817: return 7828;
          }
          return 0;
        case 97:
          switch (ch2) {
            case 768: return 224;
            case 769: return 225;
            case 770: return 226;
            case 771: return 227;
            case 772: return 257;
            case 774: return 259;
            case 775: return 551;
            case 776: return 228;
            case 777: return 7843;
            case 778: return 229;
            case 780: return 462;
            case 783: return 513;
            case 785: return 515;
            case 803: return 7841;
            case 805: return 7681;
            case 808: return 261;
          }
          return 0;
        case 98:
          switch (ch2) {
            case 775: return 7683;
            case 803: return 7685;
            case 817: return 7687;
          }
          return 0;
        case 99:
          switch (ch2) {
            case 769: return 263;
            case 770: return 265;
            case 775: return 267;
            case 780: return 269;
            case 807: return 231;
          }
          return 0;
        case 100:
          switch (ch2) {
            case 775: return 7691;
            case 780: return 271;
            case 803: return 7693;
            case 807: return 7697;
            case 813: return 7699;
            case 817: return 7695;
          }
          return 0;
        case 101:
          switch (ch2) {
            case 768: return 232;
            case 769: return 233;
            case 770: return 234;
            case 771: return 7869;
            case 772: return 275;
            case 774: return 277;
            case 775: return 279;
            case 776: return 235;
            case 777: return 7867;
            case 780: return 283;
            case 783: return 517;
            case 785: return 519;
            case 803: return 7865;
            case 807: return 553;
            case 808: return 281;
            case 813: return 7705;
            case 816: return 7707;
          }
          return 0;
        case 102:
          switch (ch2) {
            case 775: return 7711;
          }
          return 0;
        case 103:
          switch (ch2) {
            case 769: return 501;
            case 770: return 285;
            case 772: return 7713;
            case 774: return 287;
            case 775: return 289;
            case 780: return 487;
            case 807: return 291;
          }
          return 0;
        case 104:
          switch (ch2) {
            case 770: return 293;
            case 775: return 7715;
            case 776: return 7719;
            case 780: return 543;
            case 803: return 7717;
            case 807: return 7721;
            case 814: return 7723;
            case 817: return 7830;
          }
          return 0;
        case 105:
          switch (ch2) {
            case 768: return 236;
            case 769: return 237;
            case 770: return 238;
            case 771: return 297;
            case 772: return 299;
            case 774: return 301;
            case 776: return 239;
            case 777: return 7881;
            case 780: return 464;
            case 783: return 521;
            case 785: return 523;
            case 803: return 7883;
            case 808: return 303;
            case 816: return 7725;
          }
          return 0;
        case 106:
          switch (ch2) {
            case 770: return 309;
            case 780: return 496;
          }
          return 0;
        case 107:
          switch (ch2) {
            case 769: return 7729;
            case 780: return 489;
            case 803: return 7731;
            case 807: return 311;
            case 817: return 7733;
          }
          return 0;
        case 108:
          switch (ch2) {
            case 769: return 314;
            case 780: return 318;
            case 803: return 7735;
            case 807: return 316;
            case 813: return 7741;
            case 817: return 7739;
          }
          return 0;
        case 109:
          switch (ch2) {
            case 769: return 7743;
            case 775: return 7745;
            case 803: return 7747;
          }
          return 0;
        case 110:
          switch (ch2) {
            case 768: return 505;
            case 769: return 324;
            case 771: return 241;
            case 775: return 7749;
            case 780: return 328;
            case 803: return 7751;
            case 807: return 326;
            case 813: return 7755;
            case 817: return 7753;
          }
          return 0;
        case 111:
          switch (ch2) {
            case 768: return 242;
            case 769: return 243;
            case 770: return 244;
            case 771: return 245;
            case 772: return 333;
            case 774: return 335;
            case 775: return 559;
            case 776: return 246;
            case 777: return 7887;
            case 779: return 337;
            case 780: return 466;
            case 783: return 525;
            case 785: return 527;
            case 795: return 417;
            case 803: return 7885;
            case 808: return 491;
          }
          return 0;
        case 112:
          switch (ch2) {
            case 769: return 7765;
            case 775: return 7767;
          }
          return 0;
        case 114:
          switch (ch2) {
            case 769: return 341;
            case 775: return 7769;
            case 780: return 345;
            case 783: return 529;
            case 785: return 531;
            case 803: return 7771;
            case 807: return 343;
            case 817: return 7775;
          }
          return 0;
        case 115:
          switch (ch2) {
            case 769: return 347;
            case 770: return 349;
            case 775: return 7777;
            case 780: return 353;
            case 803: return 7779;
            case 806: return 537;
            case 807: return 351;
          }
          return 0;
        case 116:
          switch (ch2) {
            case 775: return 7787;
            case 776: return 7831;
            case 780: return 357;
            case 803: return 7789;
            case 806: return 539;
            case 807: return 355;
            case 813: return 7793;
            case 817: return 7791;
          }
          return 0;
        case 117:
          switch (ch2) {
            case 768: return 249;
            case 769: return 250;
            case 770: return 251;
            case 771: return 361;
            case 772: return 363;
            case 774: return 365;
            case 776: return 252;
            case 777: return 7911;
            case 778: return 367;
            case 779: return 369;
            case 780: return 468;
            case 783: return 533;
            case 785: return 535;
            case 795: return 432;
            case 803: return 7909;
            case 804: return 7795;
            case 808: return 371;
            case 813: return 7799;
            case 816: return 7797;
          }
          return 0;
        case 118:
          switch (ch2) {
            case 771: return 7805;
            case 803: return 7807;
          }
          return 0;
        case 119:
          switch (ch2) {
            case 768: return 7809;
            case 769: return 7811;
            case 770: return 373;
            case 775: return 7815;
            case 776: return 7813;
            case 778: return 7832;
            case 803: return 7817;
          }
          return 0;
        case 120:
          switch (ch2) {
            case 775: return 7819;
            case 776: return 7821;
          }
          return 0;
        case 121:
          switch (ch2) {
            case 768: return 7923;
            case 769: return 253;
            case 770: return 375;
            case 771: return 7929;
            case 772: return 563;
            case 775: return 7823;
            case 776: return 255;
            case 777: return 7927;
            case 778: return 7833;
            case 803: return 7925;
          }
          return 0;
        case 122:
          switch (ch2) {
            case 769: return 378;
            case 770: return 7825;
            case 775: return 380;
            case 780: return 382;
            case 803: return 7827;
            case 817: return 7829;
          }
          return 0;
        case 168:
          switch (ch2) {
            case 768: return 8173;
            case 769: return 901;
            case 834: return 8129;
          }
          return 0;
        case 194:
          switch (ch2) {
            case 768: return 7846;
            case 769: return 7844;
            case 771: return 7850;
            case 777: return 7848;
          }
          return 0;
        case 196:
          switch (ch2) {
            case 772: return 478;
          }
          return 0;
        case 197:
          switch (ch2) {
            case 769: return 506;
          }
          return 0;
        case 198:
          switch (ch2) {
            case 769: return 508;
            case 772: return 482;
          }
          return 0;
        case 199:
          switch (ch2) {
            case 769: return 7688;
          }
          return 0;
        case 202:
          switch (ch2) {
            case 768: return 7872;
            case 769: return 7870;
            case 771: return 7876;
            case 777: return 7874;
          }
          return 0;
        case 207:
          switch (ch2) {
            case 769: return 7726;
          }
          return 0;
        case 212:
          switch (ch2) {
            case 768: return 7890;
            case 769: return 7888;
            case 771: return 7894;
            case 777: return 7892;
          }
          return 0;
        case 213:
          switch (ch2) {
            case 769: return 7756;
            case 772: return 556;
            case 776: return 7758;
          }
          return 0;
        case 214:
          switch (ch2) {
            case 772: return 554;
          }
          return 0;
        case 216:
          switch (ch2) {
            case 769: return 510;
          }
          return 0;
        case 220:
          switch (ch2) {
            case 768: return 475;
            case 769: return 471;
            case 772: return 469;
            case 780: return 473;
          }
          return 0;
        case 226:
          switch (ch2) {
            case 768: return 7847;
            case 769: return 7845;
            case 771: return 7851;
            case 777: return 7849;
          }
          return 0;
        case 228:
          switch (ch2) {
            case 772: return 479;
          }
          return 0;
        case 229:
          switch (ch2) {
            case 769: return 507;
          }
          return 0;
        case 230:
          switch (ch2) {
            case 769: return 509;
            case 772: return 483;
          }
          return 0;
        case 231:
          switch (ch2) {
            case 769: return 7689;
          }
          return 0;
        case 234:
          switch (ch2) {
            case 768: return 7873;
            case 769: return 7871;
            case 771: return 7877;
            case 777: return 7875;
          }
          return 0;
        case 239:
          switch (ch2) {
            case 769: return 7727;
          }
          return 0;
        case 244:
          switch (ch2) {
            case 768: return 7891;
            case 769: return 7889;
            case 771: return 7895;
            case 777: return 7893;
          }
          return 0;
        case 245:
          switch (ch2) {
            case 769: return 7757;
            case 772: return 557;
            case 776: return 7759;
          }
          return 0;
        case 246:
          switch (ch2) {
            case 772: return 555;
          }
          return 0;
        case 248:
          switch (ch2) {
            case 769: return 511;
          }
          return 0;
        case 252:
          switch (ch2) {
            case 768: return 476;
            case 769: return 472;
            case 772: return 470;
            case 780: return 474;
          }
          return 0;
      }
      return 0;
    case 1:
      switch (ch1) {
        case 258:
          switch (ch2) {
            case 768: return 7856;
            case 769: return 7854;
            case 771: return 7860;
            case 777: return 7858;
          }
          return 0;
        case 259:
          switch (ch2) {
            case 768: return 7857;
            case 769: return 7855;
            case 771: return 7861;
            case 777: return 7859;
          }
          return 0;
        case 274:
          switch (ch2) {
            case 768: return 7700;
            case 769: return 7702;
          }
          return 0;
        case 275:
          switch (ch2) {
            case 768: return 7701;
            case 769: return 7703;
          }
          return 0;
        case 332:
          switch (ch2) {
            case 768: return 7760;
            case 769: return 7762;
          }
          return 0;
        case 333:
          switch (ch2) {
            case 768: return 7761;
            case 769: return 7763;
          }
          return 0;
        case 346:
          switch (ch2) {
            case 775: return 7780;
          }
          return 0;
        case 347:
          switch (ch2) {
            case 775: return 7781;
          }
          return 0;
        case 352:
          switch (ch2) {
            case 775: return 7782;
          }
          return 0;
        case 353:
          switch (ch2) {
            case 775: return 7783;
          }
          return 0;
        case 360:
          switch (ch2) {
            case 769: return 7800;
          }
          return 0;
        case 361:
          switch (ch2) {
            case 769: return 7801;
          }
          return 0;
        case 362:
          switch (ch2) {
            case 776: return 7802;
          }
          return 0;
        case 363:
          switch (ch2) {
            case 776: return 7803;
          }
          return 0;
        case 383:
          switch (ch2) {
            case 775: return 7835;
          }
          return 0;
        case 416:
          switch (ch2) {
            case 768: return 7900;
            case 769: return 7898;
            case 771: return 7904;
            case 777: return 7902;
            case 803: return 7906;
          }
          return 0;
        case 417:
          switch (ch2) {
            case 768: return 7901;
            case 769: return 7899;
            case 771: return 7905;
            case 777: return 7903;
            case 803: return 7907;
          }
          return 0;
        case 431:
          switch (ch2) {
            case 768: return 7914;
            case 769: return 7912;
            case 771: return 7918;
            case 777: return 7916;
            case 803: return 7920;
          }
          return 0;
        case 432:
          switch (ch2) {
            case 768: return 7915;
            case 769: return 7913;
            case 771: return 7919;
            case 777: return 7917;
            case 803: return 7921;
          }
          return 0;
        case 439:
          switch (ch2) {
            case 780: return 494;
          }
          return 0;
        case 490:
          switch (ch2) {
            case 772: return 492;
          }
          return 0;
        case 491:
          switch (ch2) {
            case 772: return 493;
          }
          return 0;
      }
      return 0;
    case 2:
      switch (ch1) {
        case 550:
          switch (ch2) {
            case 772: return 480;
          }
          return 0;
        case 551:
          switch (ch2) {
            case 772: return 481;
          }
          return 0;
        case 552:
          switch (ch2) {
            case 774: return 7708;
          }
          return 0;
        case 553:
          switch (ch2) {
            case 774: return 7709;
          }
          return 0;
        case 558:
          switch (ch2) {
            case 772: return 560;
          }
          return 0;
        case 559:
          switch (ch2) {
            case 772: return 561;
          }
          return 0;
        case 658:
          switch (ch2) {
            case 780: return 495;
          }
          return 0;
      }
      return 0;
    case 3:
      switch (ch1) {
        case 776:
          switch (ch2) {
            case 769: return 836;
          }
          return 0;
        case 913:
          switch (ch2) {
            case 768: return 8122;
            case 769: return 902;
            case 772: return 8121;
            case 774: return 8120;
            case 787: return 7944;
            case 788: return 7945;
            case 837: return 8124;
          }
          return 0;
        case 917:
          switch (ch2) {
            case 768: return 8136;
            case 769: return 904;
            case 787: return 7960;
            case 788: return 7961;
          }
          return 0;
        case 919:
          switch (ch2) {
            case 768: return 8138;
            case 769: return 905;
            case 787: return 7976;
            case 788: return 7977;
            case 837: return 8140;
          }
          return 0;
        case 921:
          switch (ch2) {
            case 768: return 8154;
            case 769: return 906;
            case 772: return 8153;
            case 774: return 8152;
            case 776: return 938;
            case 787: return 7992;
            case 788: return 7993;
          }
          return 0;
        case 927:
          switch (ch2) {
            case 768: return 8184;
            case 769: return 908;
            case 787: return 8008;
            case 788: return 8009;
          }
          return 0;
        case 929:
          switch (ch2) {
            case 788: return 8172;
          }
          return 0;
        case 933:
          switch (ch2) {
            case 768: return 8170;
            case 769: return 910;
            case 772: return 8169;
            case 774: return 8168;
            case 776: return 939;
            case 788: return 8025;
          }
          return 0;
        case 937:
          switch (ch2) {
            case 768: return 8186;
            case 769: return 911;
            case 787: return 8040;
            case 788: return 8041;
            case 837: return 8188;
          }
          return 0;
        case 940:
          switch (ch2) {
            case 837: return 8116;
          }
          return 0;
        case 942:
          switch (ch2) {
            case 837: return 8132;
          }
          return 0;
        case 945:
          switch (ch2) {
            case 768: return 8048;
            case 769: return 940;
            case 772: return 8113;
            case 774: return 8112;
            case 787: return 7936;
            case 788: return 7937;
            case 834: return 8118;
            case 837: return 8115;
          }
          return 0;
        case 949:
          switch (ch2) {
            case 768: return 8050;
            case 769: return 941;
            case 787: return 7952;
            case 788: return 7953;
          }
          return 0;
        case 951:
          switch (ch2) {
            case 768: return 8052;
            case 769: return 942;
            case 787: return 7968;
            case 788: return 7969;
            case 834: return 8134;
            case 837: return 8131;
          }
          return 0;
        case 953:
          switch (ch2) {
            case 768: return 8054;
            case 769: return 943;
            case 772: return 8145;
            case 774: return 8144;
            case 776: return 970;
            case 787: return 7984;
            case 788: return 7985;
            case 834: return 8150;
          }
          return 0;
        case 959:
          switch (ch2) {
            case 768: return 8056;
            case 769: return 972;
            case 787: return 8000;
            case 788: return 8001;
          }
          return 0;
        case 961:
          switch (ch2) {
            case 787: return 8164;
            case 788: return 8165;
          }
          return 0;
        case 965:
          switch (ch2) {
            case 768: return 8058;
            case 769: return 973;
            case 772: return 8161;
            case 774: return 8160;
            case 776: return 971;
            case 787: return 8016;
            case 788: return 8017;
            case 834: return 8166;
          }
          return 0;
        case 969:
          switch (ch2) {
            case 768: return 8060;
            case 769: return 974;
            case 787: return 8032;
            case 788: return 8033;
            case 834: return 8182;
            case 837: return 8179;
          }
          return 0;
        case 970:
          switch (ch2) {
            case 768: return 8146;
            case 769: return 912;
            case 834: return 8151;
          }
          return 0;
        case 971:
          switch (ch2) {
            case 768: return 8162;
            case 769: return 944;
            case 834: return 8167;
          }
          return 0;
        case 974:
          switch (ch2) {
            case 837: return 8180;
          }
          return 0;
        case 978:
          switch (ch2) {
            case 769: return 979;
            case 776: return 980;
          }
          return 0;
      }
      return 0;
    case 4:
      switch (ch1) {
        case 1030:
          switch (ch2) {
            case 776: return 1031;
          }
          return 0;
        case 1040:
          switch (ch2) {
            case 774: return 1232;
            case 776: return 1234;
          }
          return 0;
        case 1043:
          switch (ch2) {
            case 769: return 1027;
          }
          return 0;
        case 1045:
          switch (ch2) {
            case 768: return 1024;
            case 774: return 1238;
            case 776: return 1025;
          }
          return 0;
        case 1046:
          switch (ch2) {
            case 774: return 1217;
            case 776: return 1244;
          }
          return 0;
        case 1047:
          switch (ch2) {
            case 776: return 1246;
          }
          return 0;
        case 1048:
          switch (ch2) {
            case 768: return 1037;
            case 772: return 1250;
            case 774: return 1049;
            case 776: return 1252;
          }
          return 0;
        case 1050:
          switch (ch2) {
            case 769: return 1036;
          }
          return 0;
        case 1054:
          switch (ch2) {
            case 776: return 1254;
          }
          return 0;
        case 1059:
          switch (ch2) {
            case 772: return 1262;
            case 774: return 1038;
            case 776: return 1264;
            case 779: return 1266;
          }
          return 0;
        case 1063:
          switch (ch2) {
            case 776: return 1268;
          }
          return 0;
        case 1067:
          switch (ch2) {
            case 776: return 1272;
          }
          return 0;
        case 1069:
          switch (ch2) {
            case 776: return 1260;
          }
          return 0;
        case 1072:
          switch (ch2) {
            case 774: return 1233;
            case 776: return 1235;
          }
          return 0;
        case 1075:
          switch (ch2) {
            case 769: return 1107;
          }
          return 0;
        case 1077:
          switch (ch2) {
            case 768: return 1104;
            case 774: return 1239;
            case 776: return 1105;
          }
          return 0;
        case 1078:
          switch (ch2) {
            case 774: return 1218;
            case 776: return 1245;
          }
          return 0;
        case 1079:
          switch (ch2) {
            case 776: return 1247;
          }
          return 0;
        case 1080:
          switch (ch2) {
            case 768: return 1117;
            case 772: return 1251;
            case 774: return 1081;
            case 776: return 1253;
          }
          return 0;
        case 1082:
          switch (ch2) {
            case 769: return 1116;
          }
          return 0;
        case 1086:
          switch (ch2) {
            case 776: return 1255;
          }
          return 0;
        case 1091:
          switch (ch2) {
            case 772: return 1263;
            case 774: return 1118;
            case 776: return 1265;
            case 779: return 1267;
          }
          return 0;
        case 1095:
          switch (ch2) {
            case 776: return 1269;
          }
          return 0;
        case 1099:
          switch (ch2) {
            case 776: return 1273;
          }
          return 0;
        case 1101:
          switch (ch2) {
            case 776: return 1261;
          }
          return 0;
        case 1110:
          switch (ch2) {
            case 776: return 1111;
          }
          return 0;
        case 1140:
          switch (ch2) {
            case 783: return 1142;
          }
          return 0;
        case 1141:
          switch (ch2) {
            case 783: return 1143;
          }
          return 0;
        case 1240:
          switch (ch2) {
            case 776: return 1242;
          }
          return 0;
        case 1241:
          switch (ch2) {
            case 776: return 1243;
          }
          return 0;
        case 1256:
          switch (ch2) {
            case 776: return 1258;
          }
          return 0;
        case 1257:
          switch (ch2) {
            case 776: return 1259;
          }
          return 0;
      }
      return 0;
    case 5:
      switch (ch1) {
        case 1488:
          switch (ch2) {
            case 1463: return 64302;
            case 1464: return 64303;
            case 1468: return 64304;
          }
          return 0;
        case 1489:
          switch (ch2) {
            case 1468: return 64305;
            case 1471: return 64332;
          }
          return 0;
        case 1490:
          switch (ch2) {
            case 1468: return 64306;
          }
          return 0;
        case 1491:
          switch (ch2) {
            case 1468: return 64307;
          }
          return 0;
        case 1492:
          switch (ch2) {
            case 1468: return 64308;
          }
          return 0;
        case 1493:
          switch (ch2) {
            case 1465: return 64331;
            case 1468: return 64309;
          }
          return 0;
        case 1494:
          switch (ch2) {
            case 1468: return 64310;
          }
          return 0;
        case 1496:
          switch (ch2) {
            case 1468: return 64312;
          }
          return 0;
        case 1497:
          switch (ch2) {
            case 1460: return 64285;
            case 1468: return 64313;
          }
          return 0;
        case 1498:
          switch (ch2) {
            case 1468: return 64314;
          }
          return 0;
        case 1499:
          switch (ch2) {
            case 1468: return 64315;
            case 1471: return 64333;
          }
          return 0;
        case 1500:
          switch (ch2) {
            case 1468: return 64316;
          }
          return 0;
        case 1502:
          switch (ch2) {
            case 1468: return 64318;
          }
          return 0;
        case 1504:
          switch (ch2) {
            case 1468: return 64320;
          }
          return 0;
        case 1505:
          switch (ch2) {
            case 1468: return 64321;
          }
          return 0;
        case 1507:
          switch (ch2) {
            case 1468: return 64323;
          }
          return 0;
        case 1508:
          switch (ch2) {
            case 1468: return 64324;
            case 1471: return 64334;
          }
          return 0;
        case 1510:
          switch (ch2) {
            case 1468: return 64326;
          }
          return 0;
        case 1511:
          switch (ch2) {
            case 1468: return 64327;
          }
          return 0;
        case 1512:
          switch (ch2) {
            case 1468: return 64328;
          }
          return 0;
        case 1513:
          switch (ch2) {
            case 1468: return 64329;
            case 1473: return 64298;
            case 1474: return 64299;
          }
          return 0;
        case 1514:
          switch (ch2) {
            case 1468: return 64330;
          }
          return 0;
        case 1522:
          switch (ch2) {
            case 1463: return 64287;
          }
          return 0;
      }
      return 0;
    case 6:
      switch (ch1) {
        case 1575:
          switch (ch2) {
            case 1619: return 1570;
            case 1620: return 1571;
            case 1621: return 1573;
          }
          return 0;
        case 1608:
          switch (ch2) {
            case 1620: return 1572;
          }
          return 0;
        case 1610:
          switch (ch2) {
            case 1620: return 1574;
          }
          return 0;
        case 1729:
          switch (ch2) {
            case 1620: return 1730;
          }
          return 0;
        case 1746:
          switch (ch2) {
            case 1620: return 1747;
          }
          return 0;
        case 1749:
          switch (ch2) {
            case 1620: return 1728;
          }
          return 0;
      }
      return 0;
    case 9:
      switch (ch1) {
        case 2325:
          switch (ch2) {
            case 2364: return 2392;
          }
          return 0;
        case 2326:
          switch (ch2) {
            case 2364: return 2393;
          }
          return 0;
        case 2327:
          switch (ch2) {
            case 2364: return 2394;
          }
          return 0;
        case 2332:
          switch (ch2) {
            case 2364: return 2395;
          }
          return 0;
        case 2337:
          switch (ch2) {
            case 2364: return 2396;
          }
          return 0;
        case 2338:
          switch (ch2) {
            case 2364: return 2397;
          }
          return 0;
        case 2344:
          switch (ch2) {
            case 2364: return 2345;
          }
          return 0;
        case 2347:
          switch (ch2) {
            case 2364: return 2398;
          }
          return 0;
        case 2351:
          switch (ch2) {
            case 2364: return 2399;
          }
          return 0;
        case 2352:
          switch (ch2) {
            case 2364: return 2353;
          }
          return 0;
        case 2355:
          switch (ch2) {
            case 2364: return 2356;
          }
          return 0;
        case 2465:
          switch (ch2) {
            case 2492: return 2524;
          }
          return 0;
        case 2466:
          switch (ch2) {
            case 2492: return 2525;
          }
          return 0;
        case 2479:
          switch (ch2) {
            case 2492: return 2527;
          }
          return 0;
        case 2503:
          switch (ch2) {
            case 2494: return 2507;
            case 2519: return 2508;
          }
          return 0;
      }
      return 0;
    case 10:
      switch (ch1) {
        case 2582:
          switch (ch2) {
            case 2620: return 2649;
          }
          return 0;
        case 2583:
          switch (ch2) {
            case 2620: return 2650;
          }
          return 0;
        case 2588:
          switch (ch2) {
            case 2620: return 2651;
          }
          return 0;
        case 2603:
          switch (ch2) {
            case 2620: return 2654;
          }
          return 0;
        case 2610:
          switch (ch2) {
            case 2620: return 2611;
          }
          return 0;
        case 2616:
          switch (ch2) {
            case 2620: return 2614;
          }
          return 0;
      }
      return 0;
    case 11:
      switch (ch1) {
        case 2849:
          switch (ch2) {
            case 2876: return 2908;
          }
          return 0;
        case 2850:
          switch (ch2) {
            case 2876: return 2909;
          }
          return 0;
        case 2887:
          switch (ch2) {
            case 2878: return 2891;
            case 2902: return 2888;
            case 2903: return 2892;
          }
          return 0;
        case 2962:
          switch (ch2) {
            case 3031: return 2964;
          }
          return 0;
        case 3014:
          switch (ch2) {
            case 3006: return 3018;
            case 3031: return 3020;
          }
          return 0;
        case 3015:
          switch (ch2) {
            case 3006: return 3019;
          }
          return 0;
      }
      return 0;
    case 12:
      switch (ch1) {
        case 3142:
          switch (ch2) {
            case 3158: return 3144;
          }
          return 0;
        case 3263:
          switch (ch2) {
            case 3285: return 3264;
          }
          return 0;
        case 3270:
          switch (ch2) {
            case 3266: return 3274;
            case 3285: return 3271;
            case 3286: return 3272;
          }
          return 0;
        case 3274:
          switch (ch2) {
            case 3285: return 3275;
          }
          return 0;
      }
      return 0;
    case 13:
      switch (ch1) {
        case 3398:
          switch (ch2) {
            case 3390: return 3402;
            case 3415: return 3404;
          }
          return 0;
        case 3399:
          switch (ch2) {
            case 3390: return 3403;
          }
          return 0;
        case 3545:
          switch (ch2) {
            case 3530: return 3546;
            case 3535: return 3548;
            case 3551: return 3550;
          }
          return 0;
        case 3548:
          switch (ch2) {
            case 3530: return 3549;
          }
          return 0;
      }
      return 0;
    case 15:
      switch (ch1) {
        case 3904:
          switch (ch2) {
            case 4021: return 3945;
          }
          return 0;
        case 3906:
          switch (ch2) {
            case 4023: return 3907;
          }
          return 0;
        case 3916:
          switch (ch2) {
            case 4023: return 3917;
          }
          return 0;
        case 3921:
          switch (ch2) {
            case 4023: return 3922;
          }
          return 0;
        case 3926:
          switch (ch2) {
            case 4023: return 3927;
          }
          return 0;
        case 3931:
          switch (ch2) {
            case 4023: return 3932;
          }
          return 0;
        case 3953:
          switch (ch2) {
            case 3954: return 3955;
            case 3956: return 3957;
            case 3968: return 3969;
          }
          return 0;
        case 3984:
          switch (ch2) {
            case 4021: return 4025;
          }
          return 0;
        case 3986:
          switch (ch2) {
            case 4023: return 3987;
          }
          return 0;
        case 3996:
          switch (ch2) {
            case 4023: return 3997;
          }
          return 0;
        case 4001:
          switch (ch2) {
            case 4023: return 4002;
          }
          return 0;
        case 4006:
          switch (ch2) {
            case 4023: return 4007;
          }
          return 0;
        case 4011:
          switch (ch2) {
            case 4023: return 4012;
          }
          return 0;
        case 4018:
          switch (ch2) {
            case 3968: return 3958;
          }
          return 0;
        case 4019:
          switch (ch2) {
            case 3968: return 3960;
          }
          return 0;
      }
      return 0;
    case 16:
      switch (ch1) {
        case 4133:
          switch (ch2) {
            case 4142: return 4134;
          }
          return 0;
      }
      return 0;
    case 30:
      switch (ch1) {
        case 7734:
          switch (ch2) {
            case 772: return 7736;
          }
          return 0;
        case 7735:
          switch (ch2) {
            case 772: return 7737;
          }
          return 0;
        case 7770:
          switch (ch2) {
            case 772: return 7772;
          }
          return 0;
        case 7771:
          switch (ch2) {
            case 772: return 7773;
          }
          return 0;
        case 7778:
          switch (ch2) {
            case 775: return 7784;
          }
          return 0;
        case 7779:
          switch (ch2) {
            case 775: return 7785;
          }
          return 0;
        case 7840:
          switch (ch2) {
            case 770: return 7852;
            case 774: return 7862;
          }
          return 0;
        case 7841:
          switch (ch2) {
            case 770: return 7853;
            case 774: return 7863;
          }
          return 0;
        case 7864:
          switch (ch2) {
            case 770: return 7878;
          }
          return 0;
        case 7865:
          switch (ch2) {
            case 770: return 7879;
          }
          return 0;
        case 7884:
          switch (ch2) {
            case 770: return 7896;
          }
          return 0;
        case 7885:
          switch (ch2) {
            case 770: return 7897;
          }
          return 0;
      }
      return 0;
    case 31:
      switch (ch1) {
        case 7936:
          switch (ch2) {
            case 768: return 7938;
            case 769: return 7940;
            case 834: return 7942;
            case 837: return 8064;
          }
          return 0;
        case 7937:
          switch (ch2) {
            case 768: return 7939;
            case 769: return 7941;
            case 834: return 7943;
            case 837: return 8065;
          }
          return 0;
        case 7938:
          switch (ch2) {
            case 837: return 8066;
          }
          return 0;
        case 7939:
          switch (ch2) {
            case 837: return 8067;
          }
          return 0;
        case 7940:
          switch (ch2) {
            case 837: return 8068;
          }
          return 0;
        case 7941:
          switch (ch2) {
            case 837: return 8069;
          }
          return 0;
        case 7942:
          switch (ch2) {
            case 837: return 8070;
          }
          return 0;
        case 7943:
          switch (ch2) {
            case 837: return 8071;
          }
          return 0;
        case 7944:
          switch (ch2) {
            case 768: return 7946;
            case 769: return 7948;
            case 834: return 7950;
            case 837: return 8072;
          }
          return 0;
        case 7945:
          switch (ch2) {
            case 768: return 7947;
            case 769: return 7949;
            case 834: return 7951;
            case 837: return 8073;
          }
          return 0;
        case 7946:
          switch (ch2) {
            case 837: return 8074;
          }
          return 0;
        case 7947:
          switch (ch2) {
            case 837: return 8075;
          }
          return 0;
        case 7948:
          switch (ch2) {
            case 837: return 8076;
          }
          return 0;
        case 7949:
          switch (ch2) {
            case 837: return 8077;
          }
          return 0;
        case 7950:
          switch (ch2) {
            case 837: return 8078;
          }
          return 0;
        case 7951:
          switch (ch2) {
            case 837: return 8079;
          }
          return 0;
        case 7952:
          switch (ch2) {
            case 768: return 7954;
            case 769: return 7956;
          }
          return 0;
        case 7953:
          switch (ch2) {
            case 768: return 7955;
            case 769: return 7957;
          }
          return 0;
        case 7960:
          switch (ch2) {
            case 768: return 7962;
            case 769: return 7964;
          }
          return 0;
        case 7961:
          switch (ch2) {
            case 768: return 7963;
            case 769: return 7965;
          }
          return 0;
        case 7968:
          switch (ch2) {
            case 768: return 7970;
            case 769: return 7972;
            case 834: return 7974;
            case 837: return 8080;
          }
          return 0;
        case 7969:
          switch (ch2) {
            case 768: return 7971;
            case 769: return 7973;
            case 834: return 7975;
            case 837: return 8081;
          }
          return 0;
        case 7970:
          switch (ch2) {
            case 837: return 8082;
          }
          return 0;
        case 7971:
          switch (ch2) {
            case 837: return 8083;
          }
          return 0;
        case 7972:
          switch (ch2) {
            case 837: return 8084;
          }
          return 0;
        case 7973:
          switch (ch2) {
            case 837: return 8085;
          }
          return 0;
        case 7974:
          switch (ch2) {
            case 837: return 8086;
          }
          return 0;
        case 7975:
          switch (ch2) {
            case 837: return 8087;
          }
          return 0;
        case 7976:
          switch (ch2) {
            case 768: return 7978;
            case 769: return 7980;
            case 834: return 7982;
            case 837: return 8088;
          }
          return 0;
        case 7977:
          switch (ch2) {
            case 768: return 7979;
            case 769: return 7981;
            case 834: return 7983;
            case 837: return 8089;
          }
          return 0;
        case 7978:
          switch (ch2) {
            case 837: return 8090;
          }
          return 0;
        case 7979:
          switch (ch2) {
            case 837: return 8091;
          }
          return 0;
        case 7980:
          switch (ch2) {
            case 837: return 8092;
          }
          return 0;
        case 7981:
          switch (ch2) {
            case 837: return 8093;
          }
          return 0;
        case 7982:
          switch (ch2) {
            case 837: return 8094;
          }
          return 0;
        case 7983:
          switch (ch2) {
            case 837: return 8095;
          }
          return 0;
        case 7984:
          switch (ch2) {
            case 768: return 7986;
            case 769: return 7988;
            case 834: return 7990;
          }
          return 0;
        case 7985:
          switch (ch2) {
            case 768: return 7987;
            case 769: return 7989;
            case 834: return 7991;
          }
          return 0;
        case 7992:
          switch (ch2) {
            case 768: return 7994;
            case 769: return 7996;
            case 834: return 7998;
          }
          return 0;
        case 7993:
          switch (ch2) {
            case 768: return 7995;
            case 769: return 7997;
            case 834: return 7999;
          }
          return 0;
        case 8000:
          switch (ch2) {
            case 768: return 8002;
            case 769: return 8004;
          }
          return 0;
        case 8001:
          switch (ch2) {
            case 768: return 8003;
            case 769: return 8005;
          }
          return 0;
        case 8008:
          switch (ch2) {
            case 768: return 8010;
            case 769: return 8012;
          }
          return 0;
        case 8009:
          switch (ch2) {
            case 768: return 8011;
            case 769: return 8013;
          }
          return 0;
        case 8016:
          switch (ch2) {
            case 768: return 8018;
            case 769: return 8020;
            case 834: return 8022;
          }
          return 0;
        case 8017:
          switch (ch2) {
            case 768: return 8019;
            case 769: return 8021;
            case 834: return 8023;
          }
          return 0;
        case 8025:
          switch (ch2) {
            case 768: return 8027;
            case 769: return 8029;
            case 834: return 8031;
          }
          return 0;
        case 8032:
          switch (ch2) {
            case 768: return 8034;
            case 769: return 8036;
            case 834: return 8038;
            case 837: return 8096;
          }
          return 0;
        case 8033:
          switch (ch2) {
            case 768: return 8035;
            case 769: return 8037;
            case 834: return 8039;
            case 837: return 8097;
          }
          return 0;
        case 8034:
          switch (ch2) {
            case 837: return 8098;
          }
          return 0;
        case 8035:
          switch (ch2) {
            case 837: return 8099;
          }
          return 0;
        case 8036:
          switch (ch2) {
            case 837: return 8100;
          }
          return 0;
        case 8037:
          switch (ch2) {
            case 837: return 8101;
          }
          return 0;
        case 8038:
          switch (ch2) {
            case 837: return 8102;
          }
          return 0;
        case 8039:
          switch (ch2) {
            case 837: return 8103;
          }
          return 0;
        case 8040:
          switch (ch2) {
            case 768: return 8042;
            case 769: return 8044;
            case 834: return 8046;
            case 837: return 8104;
          }
          return 0;
        case 8041:
          switch (ch2) {
            case 768: return 8043;
            case 769: return 8045;
            case 834: return 8047;
            case 837: return 8105;
          }
          return 0;
        case 8042:
          switch (ch2) {
            case 837: return 8106;
          }
          return 0;
        case 8043:
          switch (ch2) {
            case 837: return 8107;
          }
          return 0;
        case 8044:
          switch (ch2) {
            case 837: return 8108;
          }
          return 0;
        case 8045:
          switch (ch2) {
            case 837: return 8109;
          }
          return 0;
        case 8046:
          switch (ch2) {
            case 837: return 8110;
          }
          return 0;
        case 8047:
          switch (ch2) {
            case 837: return 8111;
          }
          return 0;
        case 8048:
          switch (ch2) {
            case 837: return 8114;
          }
          return 0;
        case 8052:
          switch (ch2) {
            case 837: return 8130;
          }
          return 0;
        case 8060:
          switch (ch2) {
            case 837: return 8178;
          }
          return 0;
        case 8118:
          switch (ch2) {
            case 837: return 8119;
          }
          return 0;
        case 8127:
          switch (ch2) {
            case 768: return 8141;
            case 769: return 8142;
            case 834: return 8143;
          }
          return 0;
        case 8134:
          switch (ch2) {
            case 837: return 8135;
          }
          return 0;
        case 8182:
          switch (ch2) {
            case 837: return 8183;
          }
          return 0;
        case 8190:
          switch (ch2) {
            case 768: return 8157;
            case 769: return 8158;
            case 834: return 8159;
          }
          return 0;
      }
      return 0;
    case 33:
      switch (ch1) {
        case 8592:
          switch (ch2) {
            case 824: return 8602;
          }
          return 0;
        case 8594:
          switch (ch2) {
            case 824: return 8603;
          }
          return 0;
        case 8596:
          switch (ch2) {
            case 824: return 8622;
          }
          return 0;
        case 8656:
          switch (ch2) {
            case 824: return 8653;
          }
          return 0;
        case 8658:
          switch (ch2) {
            case 824: return 8655;
          }
          return 0;
        case 8660:
          switch (ch2) {
            case 824: return 8654;
          }
          return 0;
      }
      return 0;
    case 34:
      switch (ch1) {
        case 8707:
          switch (ch2) {
            case 824: return 8708;
          }
          return 0;
        case 8712:
          switch (ch2) {
            case 824: return 8713;
          }
          return 0;
        case 8715:
          switch (ch2) {
            case 824: return 8716;
          }
          return 0;
        case 8739:
          switch (ch2) {
            case 824: return 8740;
          }
          return 0;
        case 8741:
          switch (ch2) {
            case 824: return 8742;
          }
          return 0;
        case 8764:
          switch (ch2) {
            case 824: return 8769;
          }
          return 0;
        case 8771:
          switch (ch2) {
            case 824: return 8772;
          }
          return 0;
        case 8773:
          switch (ch2) {
            case 824: return 8775;
          }
          return 0;
        case 8776:
          switch (ch2) {
            case 824: return 8777;
          }
          return 0;
        case 8781:
          switch (ch2) {
            case 824: return 8813;
          }
          return 0;
        case 8801:
          switch (ch2) {
            case 824: return 8802;
          }
          return 0;
        case 8804:
          switch (ch2) {
            case 824: return 8816;
          }
          return 0;
        case 8805:
          switch (ch2) {
            case 824: return 8817;
          }
          return 0;
        case 8818:
          switch (ch2) {
            case 824: return 8820;
          }
          return 0;
        case 8819:
          switch (ch2) {
            case 824: return 8821;
          }
          return 0;
        case 8822:
          switch (ch2) {
            case 824: return 8824;
          }
          return 0;
        case 8823:
          switch (ch2) {
            case 824: return 8825;
          }
          return 0;
        case 8826:
          switch (ch2) {
            case 824: return 8832;
          }
          return 0;
        case 8827:
          switch (ch2) {
            case 824: return 8833;
          }
          return 0;
        case 8828:
          switch (ch2) {
            case 824: return 8928;
          }
          return 0;
        case 8829:
          switch (ch2) {
            case 824: return 8929;
          }
          return 0;
        case 8834:
          switch (ch2) {
            case 824: return 8836;
          }
          return 0;
        case 8835:
          switch (ch2) {
            case 824: return 8837;
          }
          return 0;
        case 8838:
          switch (ch2) {
            case 824: return 8840;
          }
          return 0;
        case 8839:
          switch (ch2) {
            case 824: return 8841;
          }
          return 0;
        case 8849:
          switch (ch2) {
            case 824: return 8930;
          }
          return 0;
        case 8850:
          switch (ch2) {
            case 824: return 8931;
          }
          return 0;
        case 8866:
          switch (ch2) {
            case 824: return 8876;
          }
          return 0;
        case 8872:
          switch (ch2) {
            case 824: return 8877;
          }
          return 0;
        case 8873:
          switch (ch2) {
            case 824: return 8878;
          }
          return 0;
        case 8875:
          switch (ch2) {
            case 824: return 8879;
          }
          return 0;
        case 8882:
          switch (ch2) {
            case 824: return 8938;
          }
          return 0;
        case 8883:
          switch (ch2) {
            case 824: return 8939;
          }
          return 0;
        case 8884:
          switch (ch2) {
            case 824: return 8940;
          }
          return 0;
        case 8885:
          switch (ch2) {
            case 824: return 8941;
          }
          return 0;
      }
      return 0;
    case 42:
      switch (ch1) {
        case 10973:
          switch (ch2) {
            case 824: return 10972;
          }
          return 0;
      }
      return 0;
    case 48:
      switch (ch1) {
        case 12358:
          switch (ch2) {
            case 12441: return 12436;
          }
          return 0;
        case 12363:
          switch (ch2) {
            case 12441: return 12364;
          }
          return 0;
        case 12365:
          switch (ch2) {
            case 12441: return 12366;
          }
          return 0;
        case 12367:
          switch (ch2) {
            case 12441: return 12368;
          }
          return 0;
        case 12369:
          switch (ch2) {
            case 12441: return 12370;
          }
          return 0;
        case 12371:
          switch (ch2) {
            case 12441: return 12372;
          }
          return 0;
        case 12373:
          switch (ch2) {
            case 12441: return 12374;
          }
          return 0;
        case 12375:
          switch (ch2) {
            case 12441: return 12376;
          }
          return 0;
        case 12377:
          switch (ch2) {
            case 12441: return 12378;
          }
          return 0;
        case 12379:
          switch (ch2) {
            case 12441: return 12380;
          }
          return 0;
        case 12381:
          switch (ch2) {
            case 12441: return 12382;
          }
          return 0;
        case 12383:
          switch (ch2) {
            case 12441: return 12384;
          }
          return 0;
        case 12385:
          switch (ch2) {
            case 12441: return 12386;
          }
          return 0;
        case 12388:
          switch (ch2) {
            case 12441: return 12389;
          }
          return 0;
        case 12390:
          switch (ch2) {
            case 12441: return 12391;
          }
          return 0;
        case 12392:
          switch (ch2) {
            case 12441: return 12393;
          }
          return 0;
        case 12399:
          switch (ch2) {
            case 12441: return 12400;
            case 12442: return 12401;
          }
          return 0;
        case 12402:
          switch (ch2) {
            case 12441: return 12403;
            case 12442: return 12404;
          }
          return 0;
        case 12405:
          switch (ch2) {
            case 12441: return 12406;
            case 12442: return 12407;
          }
          return 0;
        case 12408:
          switch (ch2) {
            case 12441: return 12409;
            case 12442: return 12410;
          }
          return 0;
        case 12411:
          switch (ch2) {
            case 12441: return 12412;
            case 12442: return 12413;
          }
          return 0;
        case 12445:
          switch (ch2) {
            case 12441: return 12446;
          }
          return 0;
        case 12454:
          switch (ch2) {
            case 12441: return 12532;
          }
          return 0;
        case 12459:
          switch (ch2) {
            case 12441: return 12460;
          }
          return 0;
        case 12461:
          switch (ch2) {
            case 12441: return 12462;
          }
          return 0;
        case 12463:
          switch (ch2) {
            case 12441: return 12464;
          }
          return 0;
        case 12465:
          switch (ch2) {
            case 12441: return 12466;
          }
          return 0;
        case 12467:
          switch (ch2) {
            case 12441: return 12468;
          }
          return 0;
        case 12469:
          switch (ch2) {
            case 12441: return 12470;
          }
          return 0;
        case 12471:
          switch (ch2) {
            case 12441: return 12472;
          }
          return 0;
        case 12473:
          switch (ch2) {
            case 12441: return 12474;
          }
          return 0;
        case 12475:
          switch (ch2) {
            case 12441: return 12476;
          }
          return 0;
        case 12477:
          switch (ch2) {
            case 12441: return 12478;
          }
          return 0;
        case 12479:
          switch (ch2) {
            case 12441: return 12480;
          }
          return 0;
        case 12481:
          switch (ch2) {
            case 12441: return 12482;
          }
          return 0;
        case 12484:
          switch (ch2) {
            case 12441: return 12485;
          }
          return 0;
        case 12486:
          switch (ch2) {
            case 12441: return 12487;
          }
          return 0;
        case 12488:
          switch (ch2) {
            case 12441: return 12489;
          }
          return 0;
        case 12495:
          switch (ch2) {
            case 12441: return 12496;
            case 12442: return 12497;
          }
          return 0;
        case 12498:
          switch (ch2) {
            case 12441: return 12499;
            case 12442: return 12500;
          }
          return 0;
        case 12501:
          switch (ch2) {
            case 12441: return 12502;
            case 12442: return 12503;
          }
          return 0;
        case 12504:
          switch (ch2) {
            case 12441: return 12505;
            case 12442: return 12506;
          }
          return 0;
        case 12507:
          switch (ch2) {
            case 12441: return 12508;
            case 12442: return 12509;
          }
          return 0;
        case 12527:
          switch (ch2) {
            case 12441: return 12535;
          }
          return 0;
        case 12528:
          switch (ch2) {
            case 12441: return 12536;
          }
          return 0;
        case 12529:
          switch (ch2) {
            case 12441: return 12537;
          }
          return 0;
        case 12530:
          switch (ch2) {
            case 12441: return 12538;
          }
          return 0;
        case 12541:
          switch (ch2) {
            case 12441: return 12542;
          }
          return 0;
      }
      return 0;
    case 251:
      switch (ch1) {
        case 64329:
          switch (ch2) {
            case 1473: return 64300;
            case 1474: return 64301;
          }
          return 0;
      }
      return 0;
    case 465:
      switch (ch1) {
        case 119127:
          switch (ch2) {
            case 119141: return 119134;
          }
          return 0;
        case 119128:
          switch (ch2) {
            case 119141: return 119135;
          }
          return 0;
        case 119135:
          switch (ch2) {
            case 119150: return 119136;
            case 119151: return 119137;
            case 119152: return 119138;
            case 119153: return 119139;
            case 119154: return 119140;
          }
          return 0;
        case 119225:
          switch (ch2) {
            case 119141: return 119227;
          }
          return 0;
        case 119226:
          switch (ch2) {
            case 119141: return 119228;
          }
          return 0;
        case 119227:
          switch (ch2) {
            case 119150: return 119229;
            case 119151: return 119231;
          }
          return 0;
        case 119228:
          switch (ch2) {
            case 119150: return 119230;
            case 119151: return 119232;
          }
          return 0;
      }
      return 0;
  }
  return 0;
}

glui32 buffer_canon_compose(glui32 *buf, glui32 len)
{
  glui32 curch, newch, curclass, newclass, res;
  glui32 ix, jx, pos;

  if (len == 0)
    return 0;

  pos = 0;
  curch = buf[0];
  curclass = combining_class(curch);
  if (curclass)
    curclass = 999;
  ix = 1;
  jx = ix;

  while (1)
  {
    if (jx >= len)
    {
      buf[pos] = curch;
      pos = ix;
      break;
    }
    newch = buf[jx];
    newclass = combining_class(newch);
    res = check_composition(curch, newch);
    if (res && (!curclass || curclass < newclass))
    {
      curch = res;
      buf[pos] = curch;
    }
    else
    {
      if (!newclass)
      {
        pos = ix;
        curch = newch;
      }
      curclass = newclass;
      buf[ix] = newch;
      ix++;
    }
    jx++;
  }

  return pos;
}
