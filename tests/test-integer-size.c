/**
 * Tests for integer sizes
 *
 * This can be run in Xemu in testing mode with e.g.
 *
 *     xmega65 -testing -headless -sleepless -prg test-integer-size.prg
 *
 * If a test fails, xemu will exit with a non-zero return code.
 */
#include <mega65/memory.h>
#include <stdlib.h>
#include <stdint.h>

#define XEMU_CONTROL 0xD6CF
#define XEMU_QUIT 0x42

void xemu_exit(int exit_code)
{
    POKE(XEMU_CONTROL, (uint8_t)exit_code);
    POKE(XEMU_CONTROL, XEMU_QUIT);
    exit(exit_code);
}

#define assert_eq(A, B)                                                        \
    if (A != B)                                                                \
    xemu_exit(EXIT_FAILURE)

int main(void)
{
    // Integer sizes
    assert_eq(sizeof(uint8_t), 1);
    assert_eq(sizeof(unsigned char), 1);
    assert_eq(UINT8_MAX, 0xFF);

    assert_eq(sizeof(uint16_t), 2);
    assert_eq(sizeof(unsigned int), 2);
    assert_eq(UINT16_MAX, 0xFFFF);

    assert_eq(sizeof(uint32_t), 4);
    assert_eq(sizeof(unsigned long), 4);
    assert_eq(UINT32_MAX, 0xFFFFFFFF);

    assert_eq(INT16_MAX, 0x7FFF);
    assert_eq(INT32_MAX, 0x7FFFFFFF);
    xemu_exit(EXIT_SUCCESS);
}

