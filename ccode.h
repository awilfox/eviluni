#ifndef __CCODE_H_
#define __CCODE_H_

#include <stdbool.h>
#include <stdint.h>

bool spoof_init(void);
int32_t spoof_is_evil(const char *string);

#endif /*!__CCODE_H_ */
