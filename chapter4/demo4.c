//
// Created by Zhang Shengzhe on 2020/9/5.
//

/**
 * X86-64
 * start in %rdi, count in %rsi
 * sum:
 *      movl $0, %eax
 *      jmp .L2
 * .L3:
 *      addq (%rdi), %rax
 *      addq $8, %rdi
 *      subq $1, %rsi
 * .L2:
 *      testq %rsi, %rsi
 *      jne .L3
 *      req;ret
 * -----------------------------
 * Y86-64
 * start in %rdi, count in %rsi
 * sum:
 *      irmovq $8, %r8
 *      irmovq $1, %r9
 *      xor %rax, %rax
 *      andq %rsi, %rsi
 *      jmp test
 * loop:
 *      mrmovq (%rdi), %r10
 *      addq %r10, %rax
 *      addq %r8, %rdi
 *      subq %r9, %rsi
 * test:
 *      jne loop
 *      ret
 * @param start
 * @param count
 * @return
 */
long sum(long *start, long count)
{
    long sum = 0;
    while (count) {
        sum += *start;
        start++;
        count--;
    }
    return sum;
}