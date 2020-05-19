#pragma once

#define  KEY_ESC          0x1B
#define  KEY_DASH         0x2D
#define  KEY_SHARP        0x23
#define  KEY_SLASH        0x2F
#define  KEY_BACKSLASH    0x5C
#define  KEY_CARET        0x5E

#define  IS_ALPHA(x)      ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
#define  IS_DIGIT(x)      (x >= '0' && x <= '9')
#define  TO_DIGIT(x)      (x - '0')