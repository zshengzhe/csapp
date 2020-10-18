## 处理器体系结构

**Y86-64**

![Image text](../image/1.jpg)

+ Y86-64的movq指令：irmovq、rrmovq、mrmovq、rmmovq分别显示的指明源和目的的格式。立即数i、寄存器r或内存m。
不允许从一个内存地址直接传动到另一个内存地址
+ 有4个整数操作指令 addq、subq、andq、xorq。这些指令会设置3个条件码ZF、SF和OF（零、符号和溢出）
+ 7个跳转指令 jmp、jle、jl、je、jne、jge、jg
+ 6个条件传送指令：cmovle、cmovl、cmove、cmovne、cmovge和cmovg
+ call指令和ret指令
+ pushq和popq
+ halt指令停止指令的执行
![Image text](../image/2.jpg)

### 指令编码
每条指令第一个字节表明指令的类型，高4位是代码部分，低4位是功能部分
![Image text](../image/3.jpg)
![Image text](../image/4.jpg)
**e.g.**\
rmmovq %rsp, 0x123456789abcd(%rdx)
4042cdab896745230100

### Y86-64异常
![Image text](../image/5.jpg)

### 将处理组织成阶段
+ 取指：指令指示字节icode和ifun。取出寄存器指示符字节rA和rB。取出一个8字节常数字valC\
它按顺序方式计算当前下一条指令的地址valP
+ 译码：从寄存器文件读入最多两个操作数得到valA和valB
+ 执行：ALU执行得到的值valE。可能设置条件码
+ 访存：写入内存或从内存读出数据。读出的值valM
+ 写回：最多可以写两个结果到寄存器文件
+ 更新PC：将PC设置为下一条指令的地址

![Image text](../image/6.jpg)
![Image text](../image/7.jpg)
![Image text](../image/8.jpg)
![Image text](../image/9.jpg)

###练习题
