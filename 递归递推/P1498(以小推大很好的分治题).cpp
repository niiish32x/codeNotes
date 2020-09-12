#include<iostream>
using namespace std;
char a[1024][2048];

int main(){
    // len 表示当前图腾的宽
    // len/2 是图腾的高
    int n,len=4,k=1;
    cin>>n;

    for(int i=0;i<1024;i++)
        for(int j=0;j<2048;j++)
            a[i][j]=' ';


    //倒着存n=1时的图腾 
    /*
      0  1  2  3
    0 /  _  _ \
    1   /   \ 
    输出时 则从最后一行开始从左往右输出
        /\
       /__\ 
       即为图示所要求的图形
    */

    a[0][0]=a[1][1]='/';
    a[0][1]=a[0][2]='_';
    a[0][3]=a[1][2]='\\';

    /*
    分治过程不断复制
    其实就是相当于 从最终图形的左下角开始复制
    每次len>>1 即相当于向外扩展一倍数
    但实际操作会有一个问题 那就是较为拿直接求出左下角的位置
    所以将图形倒着存 从左上角开始复制
    最后逆向输出即为答案结果
    还是很巧妙的分治+递推的过程
    */

    //tips:!! 注意!!
    //移位运算<<,>> 为第七优先级 
    //而加减运算+,-为第六优先级  乘除*，/为第5优先级
    //所以运算优先级为
    //乘除>加减>移位运算  (移位运算的优先级不高!!!)
    while(k<n){
        for(int i=0;i<len>>1;i++)
            for(int j=0;j<len;j++)
                a[i+(len>>1)][j+(len>>1)] = a[i][j+len]=a[i][j];
        len<<=1;
        k++;
    }

    for(int i=(len>>1)-1;i>=0;i--){
        for(int j=0;j<len;j++)
            cout<<a[i][j];
        cout<< endl;
    }

    return 0;
}