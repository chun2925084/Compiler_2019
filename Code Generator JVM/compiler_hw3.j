.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
ldc 1
i2f
fstore 0
LABEL_BEGIN1:
fload 0
ldc 6.0
fsub
f2i
ifge LABEL_1_1
fload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
fload 0
ldc 1
i2f
fadd
fstore 0
ldc 1
istore 1
LABEL_BEGIN2:
iload 1
ldc 6
isub
ifge LABEL_2_2
iload 1
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
iload 1
ldc 1
iadd
istore 1
goto LABEL_BEGIN2
LABEL_2_2:
ldc "ok"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto LABEL_BEGIN1
LABEL_1_1:
return
.end method
