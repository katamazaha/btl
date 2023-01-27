#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class nhanvien{
 protected:
     string hoten;
     int ma,sdt,day,mon,year;
     long luongcb;
 public:
    nhanvien(){};
    ~nhanvien(){};
    virtual void nhap()
    {
        cout<<"Ho va ten: ";fflush(stdin);getline(cin, hoten);
        cout<<"Ma nhan vien: ";cin>>ma;
        cout<<"So dien thoai: ";cin>>sdt;
        cout<<"Ngay bat dau d/m/y: ";
        cin>>day;cin.ignore();
        cin>>mon;cin.ignore();
        cin>>year;cin.ignore();
        cout<<"Luong co ban: ";cin>>luongcb;
    }
    virtual void xuat()
    {
        cout<<"Ho va ten: "<<hoten<<endl;
        cout<<"Ma nhan vien: "<<ma<<endl;
        cout<<"So dien thoai: "<<sdt<<endl;
        cout<<"Ngay bat dau: "<<day<<"/"<<mon<<"/"<<year<<endl;
        cout<<"Luong co ban: "<<luongcb<<endl;
    }
    virtual void luong(){}
    virtual long luongthang(int i){}
    long getma(){return ma;}
};
class dev:
    virtual public nhanvien
    {
    private:
        long them[12];
    public:
      dev(){};
      ~dev() {};
      virtual void nhap()
      {
          nhanvien::nhap();
          for (int i=0;i<=11;i++)
          {
          cout<<"So gio lam them thang "<<i+1<<" la: ";cin>>them[i];
          }
      }
      virtual void xuat()
      {
          nhanvien::xuat();
          for (int i=0;i<=11;i++)
          cout<<"so gio lam them thang "<<i+1<<" la: "<<them[i]<<endl;
      }
      virtual void luong()
      {
          for (int i=0;i<=11;i++)
            cout<<"Luong thang "<<i+1<<" la: "<<luongcb+them[i]*200000<<endl;
      }
      virtual long luongthang( int i)
      {
          return luongcb+them[i-1]*200000;
      }
    };
class test:
    virtual public nhanvien
    {
    private:
        int soloi[12];
    public:
      test(){};
      ~test() {};
      virtual void nhap()
      {
          nhanvien::nhap();
          for (int i=0;i<=11;i++)
          {
          cout<<"So loi phat hien thang "<<i+1<<" la: ";cin>>soloi[i];}
      }
      virtual void xuat()
      {
          nhanvien::xuat();
          for (int i=0;i<=11;i++)
          cout<<"so gio lam them thang "<<i+1<<" la: "<<soloi[i]<<endl;
      }
      virtual void luong()
      {
          for (int i=0;i<=11;i++)
          cout<<"Luong thang "<<i+1<<"l a: "<<luongcb+soloi[i]*20000<<endl;
      }
      virtual long luongthang( int i)
      {
          return luongcb+soloi[i-1]*20000;
      }
    };
class quanly
    {
    private:
        nhanvien **a;
        int n;
    public:
     quanly()
     {
         n=0;
         a= new nhanvien*[100];
     }
     ~quanly()
     {
         delete []a;
     }
     void nhap()
     {
        int k;
        for (int i=0;;i++)
        {
        cout<<"\nChon loai nhan vien:";
        cout<<"\n1. Lap trinh vien";
        cout<<"\n2. Tester";
        cout<<"\n0. Tro lai\n";
        cin>>k;
        if (k!=1 && k!=2 && k!=0) cout<<"Khong hop le";
        if (k==0) return ;
        else if (k==1)
        {
            n++;
            a[i]= new dev;
        }
        else
        {
            n++;
            a[i]= new test;
        }
        a[i]->nhap();
        }
     }
     void xuat()
     {
         cout<<"So nhan vien: "<<n<<endl;
         for(int i=0;i<n;i++)
          {
            cout<<endl;
            a[i]->xuat();
            a[i]->luong();
            cout<<endl;
          }
     }
     void them()
     {
        int k;
        cout<<"\nChon loai nhan vien:";
        cout<<"\n1. Lap trinh vien";
        cout<<"\n2. Tester\n";
        cin>>k;
        if (k!=1 && k!=2 && k!=0) cout<<"Khong hop le";
        if (k==1)
        {
            n++;
            a[n-1]= new dev;
        }
        else
        {
            n++;
            a[n-1]= new test;
        }
        a[n-1]->nhap();
     }
     void xoa(int i)
     {
         for (int k=0;k<n;k++)
         {
             if (a[k]->getma()==i)
             {
                 for(int j=k;j<n-1;j++)
                 a[j]=a[j+1];
                 n=n-1;
             }
         }
     }
     void sua (int i)
     {
        for (int m=0;m<n;m++)
         {
             if (a[m]->getma()==i)
             {
                int k;
                cout<<"\nChon loai nhan vien:";
                cout<<"\n1. Lap trinh vien";
                cout<<"\n2. Tester\n";
                cin>>k;
                if (k!=1 && k!=2 && k!=0) cout<<"Khong hop le";
                if (k==0) return ;
                else if (k==1) a[m]= new dev;
                else a[m]= new test;
                a[m]->nhap();
              }
         }
     }
     long luongtb(int i)
     {
         long tong=0;
         for (int j=0;j<n;j++)
            tong=tong+a[j]->luongthang(i);
         return (double)tong/n;
     }
    };
    void timkiem()
    {
        int n;
                cout<<endl<<"Tim kiem nhan vien theo thong tin: "<<endl;
                cout<<"1. Ten"<<endl;
                cout<<"2. Ma nhan vien"<<endl;
                cout<<"3. So dien thoai"<<endl;
                cout<<"4. Thoi gian bat dau lam viec"<<endl;
                cin>>n;
                switch (n)
                {
                case 1:
                    {
                        //x.timkiemten;
                        break;
                    }
                case 2:
                    {
                        //x.timkiemmanv;
                        break;
                    }
                case 3:
                    {
                        //x.timkiemsdt;
                        break;
                    }
                case 4:
                    {
                        //x.timkiemtime;
                        break;
                    }
                }
    }
int main()
{
    quanly x;
    int i=1,k;
    while (i==1)
    {
        cout<<"=================================="<<endl;
        cout<<"             MENU                 "<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Nhap danh sach nhan vien"<<endl;
        cout<<"2. Hien thi danh sach nhan vien"<<endl;
        cout<<"3. Them nhan vien"<<endl;
        cout<<"4. Sua thong tin nhan vien"<<endl;
        cout<<"5. Xoa nhan vien"<<endl;
        cout<<"6. Tim kiem nhan vien"<<endl;
        cout<<"7. Tinh muc luong trung binh cac nhan vien theo thang"<<endl;
        cout<<"8. Thong ke cac nhan vien co muc luong thap hon muc luong trung binh cac nhan vien theo thang"<<endl;
        cout<<"Moi ban nhap lua chon: ";cin>>k;
        switch (k)
        {
        case 1:
            {
                x.nhap();
                break;
            }
        case 2:
            {
                x.xuat();
                break;
            }
        case 3:
            {
                int n;
                cout<<endl<<"So luong nhan vien can them: ";
                cin>>n;
                for(int j=1;j<=n;j++)
                x.them();
                break;
            }
        case 4:
            {
                int n,m;
                cout<<endl<<"So luong nhan vien can sua thong tin: ";
                cin>>n;
                for (int j=1;j<=n;j++)
                {
                    cout<<endl<<"Nhap ma nhan vien can sua: ";
                    cin>>m;
                    x.sua(m);
                }
                break;
            }
        case 5:
            {
               int n,m;
               cout<<endl<<"So luong nhan vien can xoa: ";
               cin>>n;
               for (int j=1;j<=n;j++)
                {
                    cout<<endl<<"Nhap ma nhan vien can xoa: ";
                    cin>>m;
                    x.xoa(m);
                }
                break;
            }
        case 6:
            {
                timkiem();
                break;
            }
        case 7:
            {
                int n;
                cout<<endl<<"Nhap thang tinh luong trung binh cac nhan vien: ";
                cin>>n;
                while (n<0 || n>12)
                {
                    cout<<endl<<"Khong hơp le";
                    cout<<endl<<"Moi ban nhap lai: ";
                    cin>>n;
                }
                x.luongtb(n);
               break;
            }
        case 8:
            {
               int n;
                cout<<endl<<"Nhap thang thong ke cac nhan vien co muc luong thap hon trung binh: ";
                cin>>n;
                while (n<0 || n>12)
                {
                    cout<<endl<<"Khong hơp le";
                    cout<<endl<<"Moi ban nhap lai: ";
                    cin>>n;
                }
                //x.thongke;
               break;
            }
            }


        cout<<"Ban co nhap tiep khong?"<<endl;
        cout<<"1. Co"<<endl;
        cout<<"2. Khong"<<endl;
        cout<<"Moi ban nhap lua chon: ";
        cin>>i;
    }
    return 0;
}
