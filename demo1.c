# include<reg51.h>
void main(void)
{
unsigned char x,y,z, a,b,c;
x=0x2;
y=0x4;
P0=0x00;
z=x+y;
P0=z;
a=0x2;
b=0x4;
P2=0x00;
c=b*a;
P2=c;
while(1);
}
#ex2
# include<reg51.h>
void main(void)
{
unsigned char x,y,z, a,b,c;
x=0x2;
y=0x4;
P0=0x00;
z=y-x;
P0=z;
a=0x2;
b=0x4;
P2=0x00;
c=b/a;
P2=c;
while(1);
}
#ex3
# include<reg51.h>
void main(void)
{
unsigned char x,y,z, a,b,c, d;
x=0x4;
y=0x4;
P0=0x00;
z=y&x;
P0=z;
a=0x2;
b=0x4;
P2=0x00;
c=b|a;
P2=c;
P3=0x00;
d=~a;
P3=d; //port 3 is caps (P3)
while(1);
}
#ex4
# include<reg51.h>
void main(void)
{
unsigned char x,y,z, a,b,c, d ,i,j,k;
x=0x4;
y=0x4;
P0=0x00;
z=y&x;
P0=z;
a=0x2;
b=0x4;
P2=0x00;
c=b|a;
P2=c;
P3=0x00;
d=~a;
P3=d; //port 3 is caps (P3)
P1=0x00;
i=x+y;
P1=i;
P1=0x00;
j=x-y;
P1=j;
P1=0x00;
k=x*y;
P1=k;
while(1);
}
#ex5
# include<reg51.h>
void main(void)
{
unsigned char x,y,z;
x=0x4;
y=0x4;
if(x==y)
{
z=0x1; //right
P1=0x00;
P1=z;
}
x=0x4;
y=0x3;
if(x!=y)
{
z=0x2; //wrong
P2=0x00;
P2=z;
}
if(x<y)
{
z=0x2; //wrong
P2=0x00;
P2=z;
}
if(x>y)
{
z=0x1; //right
P1=0x00;
P1=z;
}
while(1);}
#ex6
ORG 0000H
MOV A, #2H
MOV B,A
MUL AB
MOV R0,A
END
#ex7
org 0000h
mov dptr,#600h //rom memory intial address
mov r0,#60h
//ram memory intial address
mov r7,#06
//count
back:movc a,@a+dptr
mov @r0, a
inc dptr
inc r0
clr a
djnz r7, back
org 600h
db 23h,45h,55h,67h,88h,97h
end

MOV
R0,#05H
MOV R1,#50H
MOV DPTR,#6000H
L1:MOV A,@R1
MOVX @DPTR,A
INC R1
INC DPL
DJNZ R0,L1
END
#ex8
mov a,#25h
mov b,#12h
add a,b
mov 40h,a
mov a,#25h
mov b,#12h
subb a,b
mov 41h,a
mov a,#25h
mov b,#12h
mul ab
mov 42h,a
mov 43h,b
mov a,#25h
mov b,#12h
div ab
mov 44h,a
mov 45h,b
mov a,#25h
inc a
mov 46h,a
dec a
end
#ex9
org 0000h
mov r0,#20h
mov r1,#05h
mov b,#00h
clr a
skip: mov a,@r0
cjne a,b,loop
loop: jc down
mov b,a
down:inc r0
djnz r1,skip
mov 30h,b
end
#ex11
from machine import Pin
from time import sleep
led=Pin(5,Pin.OUT)
pushbutton=Pin(2,Pin.IN)
print('MADE IN DR.G.U POPE COLLEGE OF ENGINEERING')
while True:
led.value(pushbutton.value())
sleep(0.5)
