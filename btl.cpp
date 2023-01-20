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
            cout<<"Luong thang "<<i+1<<" la: "<<luongcb+them[i]*200000<<"d"<<endl;
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
          cout<<"Luong thang "<<i+1<<"l a: "<<luongcb+soloi[i]*20000<<"d"<<endl;
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
        cout<<"\n1-Lap trinh vien";
        cout<<"\n2-Tester";
        cout<<"\n0-Ket thuc\n";
        cin>>k;
        if (k!=1 && k!=2 && k!=0) cout<<"Khong hop le";
        if (k==0) return;
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
    };
int main()
{
    quanly x;
    x.nhap();
    x.xuat();
    return 0;
}
