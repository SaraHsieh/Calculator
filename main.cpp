#include <iostream>
#include <stdlib.h>

using namespace std;
class hi{    //物件hi
 private:    //宣告物件中的私有資料成員、私有成員函式
      int a,b,tA,np;    //宣告物件中的變數
      int *A;    //宣告物件中的指標
      void ornot()    //宣告進退位處理的成員函式
      {
          int o=0;    //宣告整數o=0;
          if(A[tA]>=0)    //判斷陣列中的最高位數是否>=0
          {
              while(o<=tA)    //陣列內高位數以下的元素都要進行進退位的判斷
              {
                  if(A[o]>=10)    //當A[o]>=10時
                  {
                      A[o]=A[o]-10;    //A[o]=本身的餘數
                      o++;    //指定o=o+1
                      A[o]=A[o]+1;     //此時的A[o]為下一元素，要進位所以+1
                  }
                  if(A[o]<=-10)    //當A[o]<=-10時
                  {
                      A[o]=A[o]%10;    //A[o]=本身的餘數
                      o++;    //指定o=o+1
                      A[o]=A[o]-1;    //此時的A[o]為下一元素，要退位所以-1
                  }
                  if((A[o]>=0)&&(A[o]<=9))    //當A[o]>=0且A[o]<=9時
                  {
                      o++;    //指定o=o+1，不須任何進位退位處理
                  }
                  if(A[o]<0&&A[o]>-9)    //當A[o]<0且A[o]>-9時
                  {
                      A[o]=A[o]+10;    //A[o]為A[o]+10
                      o++;    //指定o=o+1
                      A[o]=A[o]-1;    //此時的A[o]為下一元素，10被借了，要退位所以-1
                  }
              }
          }
          if(A[tA]<0)    //判斷陣列中的元素是否<0
          {
              while(o<=tA)    //陣列內高位數以下的元素都要進行進退位的判斷
              {
                  if(A[o]>=10)    //當A[o]>=10時
                  {
                      A[o]=A[o]%10;    //A[o]為A[o]除10的餘數
                      o++;    //指定o=o+1
                      A[o]=A[o]+1;    //此時的A[o]為下一元素，借了-10給上一位，所以+1
                  }
                  if(A[o]<=(-10))    //當A[o]<=-10時
                  {
                      A[o]=A[o]%10;    //A[o]為A[o]除10的餘數
                      o++;    //指定o=o+1
                      A[o]=A[o]-1;    //此時的A[o]為下一元素，上一位數>-10，所以退位-1
                  }
                  if((A[o]<=0)&&(A[o]>=(-9)))    //當A[o]<=0且A[o]>=-9
                  {
                      o++;    //指定o=o+1，不需任何進位退位處理進行
                  }
                  if(A[o]>0&&A[o]<=9)    //當A[o]>0且A[o]<=-9
                  {
                      A[o]=A[o]-10;    //A[o]為A[o]-10
                      o++;    //指定o=o+1
                      A[o]=A[o]+1;    //此時的A[o]為下一元素，借了-10出去，所以+1
                  }
              }
          }
      }

 public:
     hi *next;    //宣告指標物件
     hi()    //無引數建構子
     {

     }
     hi(int m)    //有引數建構子
     {
         int i=0;    //宣告整數i=0;
         a=m;    //用a去接收引數m，a為主程式中輸入的整數m
         if(m<0)    // 當m<0時
          {
              b=-m;    //b等於m轉為正值
          }
          else    //如果m>=0
          {
              b=m;    //b等於m，即b為m的絕對值
          }
          A=new int[50];    //開出記憶體空間大小為50的陣列
          while(i<=49)    //利用while迴圈將陣列中每一個值設為零
          {
              A[i]=0;
              i++;
          }
          i=0;
          if(m==0)    //當輸入的m值為0時
          {
              A[i]=0;    //陣列中的值設為0
          }
          else    //若m值不為0
          {
              while(m>0||m<0)    //利用while迴圈將m值填入迴圈
              {
                  A[i]=m%10;
                  m=m/10;
                  i++;
              }
          }
          i=49;
          while(A[i]==0&&i>0)    //找出陣列中不為0的元素是第幾個
          {
              i--;
          }
          tA=i;    //指定tA為陣列中不為0的元素
     }
     hi(const hi&oh)    //複製建構子
     {
         this->a=oh.a;
         this->b=oh.b;
         this->tA=oh.tA;
         this->np=oh.np;
         A=new int[50];
         int i=0;
         for(i=0;i<50;i++)
         {
             this->A[i]=oh.A[i];
         }
     }
     hi operator+(const hi&yolo)    //當要作物件和物件相加時，所用的加號重載運算子，將物件的參考從主程式中傳進來當作引數
     {
         int i=0;
         for(i=0;i<50;i++)    //做物件中陣列的相加
         {
             A[i]=A[i]+yolo.A[i];
         }
         return *this;
     }
     hi operator+(int m)    //當要作物件和整數相加時，所用的加號重載運算子，將整數從主程式中傳進來當作引數
     {
         hi Q(m);    //宣告物件Q，同時呼叫有引數建構子做好設值
         int i=0;
         for(i=0;i<50;i++)    //做物件中陣列的相加
         {
             A[i]=A[i]+Q.A[i];
         }
         return *this;    //回傳this指標
     }
     hi operator=(const hi&yoyo)    //等號重載運算子，由主函式傳入另一物件的參考當作引數
     {
         a=yoyo.a;    //a等於引數的a
         b=yoyo.b;    //b等於引數的b
         tA=yoyo.tA;    //tA等於引數的tA
         np=yoyo.np;    //np等於引數的np
         A=new int[50];    //開出陣列的記憶體空間
         int i=0;
         for(i=0;i<50;i++)    //陣列等於引數的陣列
         {
             A[i]=yoyo.A[i];
         }
     }
     void setab(int n)    //a,b的設值
      {
          a=n;    //a為主程式中，輸入的數字
          if(n<0)    //b為主程式中，輸入數字的絕對值
          {
              b=-n;
          }
          else
          {
              b=n;
          }
      }
      void newA()    //開出陣列A的記憶體空間，大小為50
      {
              A=new int[50];
      }
      void setzero()    //將陣列歸零
      {
          int i=0;
          while(i<=49)
          {
              A[i]=0;
              i++;
          }
      }
      void setA(int n)   //陣列A的設值，由主程式中傳引數進來
      {
          int i=0;
          if(n==0)    //如果輸入值為0，直接填入0
          {
              A[i]=0;
          }
          else    //如果輸入值不為0
          {
              while(n>0||n<0)    //則用while迴圈將值填入陣列
              {
                  A[i]=n%10;
                  n=n/10;
                  i++;
              }
          }
      }
     void settA()    //計算陣列A中的最大位數位在陣列中哪個位置
      {
          int i=49;
          while(A[i]==0&&i>0)
          {
              i--;
          }
          tA=i;
      }
      int gettA()    //將tA回傳
      {
          return tA;
      }
      void plustogether(int *B)    //將兩個陣列相加，由主程式中傳入另一陣列的指標
      {
          int o=0;
          while(o<49)    //利用while迴圈做相加
          {
          A[o]=A[o]+B[o];
          o++;
          }
      }
      void setnp()    //判斷陣列的最高位數為正或負(為正及大於0：np=1；為負：np=0)
      {
          if(A[tA]>=0)
          {
              np=1;
          }
          else
          {
              np=0;
          }
      }
      int getnp()    //回傳np
      {
          return np;
      }
      void finish()    //呼叫私有成員函氏，做進退位的判斷
      {
          ornot();
      }
      void getoneA(int i)    //單一位數的輸出，由主程式中傳入想要的是第幾位
      {
         cout<<A[i-1];
      }
      int* getA()    //將陣列地的位置回傳
      {
          return A;
      }
};

int main()
{
    int m,j,k;    //宣告整數m,j,k
    m=1;    //m=1
    hi *ohya, *yo,B;    //宣告指標物件ohya,yo、還有物件B
    ohya=new hi();    //開出物件ohya的記憶體空間
    ohya->setab(0);    //利用成員函式將ohya中的資料成員設值
    ohya->newA();    //開出物件中的陣列
    ohya->setzero();    //將陣列歸零
    yo=ohya;    //將另一指標物件yo指向ohya，兩個指標目前都指向同一物件

    while(m!=0)    //當輸入的m值不為0時，加法計算器會繼續運算，每次運算會開一個新的指標物件，構成串列
    {
        cout<<"請輸入一個數(欲結束運算請輸入0):";    //在螢幕上顯示"請輸入一個數:"
        cin>>m;    //將使用者輸入的數字存入m
        yo->next=new hi(m);    //開出物件中的指標物件的記憶體空間，同時用有引數建構子做好設值
        yo=yo->next;    //將yo指標指向新物件
        B=(*ohya)+(*yo);    //用ohya指標物件呼叫加號重載運算子，做ohya和yo的相加；再用B物件呼叫等號重載運蒜仔
        ohya->settA();    //新物件中tA重新設值
        ohya->finish();    //相加減的進退位處理
        ohya->settA();    //tA重新設值
        ohya->setnp();    //np設值
    }
        j=B.gettA();    //將tA回傳到主程式，並用j接收
        cout<<"相加結果:";    //在螢幕上顯示"相加結果:"
        if(B.getnp()==0)    //利用np判斷相加之後的數字為正或負
        {
            cout<<B.getA()[j];    //若為負，則先輸出最大位數
            j--;    //j=j-1
        }
        while(j>=0)    //當j>=0時，利用迴圈輸出數字
        {
            if(B.getnp()==0)    //判斷若為負，則將負值轉成正，再做出輸出
            {
                cout<<-B.getA()[j];
            }
            else    //若不為負，則直接輸出
            {
                cout<<B.getA()[j];
            }
            j--;    //
        }
        cout<<endl;    //換行
        cout<<"想要第幾位的單一位數(以個位數為1、十位數為2......以此類推):";    //"想要第幾位的單一位數(以個位數為1、十位數為2......以此類推):"
        cin>>k;    //將使用者輸入的值存到k
        B.getoneA(k);    //呼叫輸出單一位數的成員函式，將k值當作引數
        cout<<endl;    //換行
        system ("pause");    //程式跑完後不要馬上關掉視窗
        return 0;    //回傳0
}
