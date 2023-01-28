#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class nhanvien{
 protected:
     string sdt,hoten;
     int ma,day,mon,year;
     long luongcb;
 public:
    nhanvien(){};
    ~nhanvien(){};
    virtual void nhap()
    {
        cout<<"Ho va ten: ";
        fflush(stdin);
        cin>>hoten;
        cout<<"Ma nhan vien: ";
        cin>>ma;
        cout<<"So dien thoai: ";
        cin>>sdt;
        cout<<"Ngay bat dau d/m/y: ";
        cin>>day; cin.ignore();
        cin>>mon; cin.ignore();
        cin>>year; cin.ignore();
        cout<<"Luong co ban: ";
        cin>>luongcb;
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
    string getten(){return hoten;}
    string getsdt(){return sdt;}
    int getday(){return day;}
    int getmon(){return mon;}
    int getyear(){return year;}
};
typedef nhanvien NV;
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
          cout<<"Luong thang "<<i+1<<" la: "<<luongcb+soloi[i]*20000<<endl;
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
         int dem=0;
         for (int k=0;k<n;k++)
         {
             if (a[k]->getma()==i)
             {
                 dem=1;
                 for(int j=k;j<n-1;j++)
                 a[j]=a[j+1];
                 a[n-1]->~nhanvien();
                 n=n-1;
             }
         }
         if(dem==0) cout<<"Ma nhan vien khong ton tai";
     }
     void sua (int i)
     {
         int dem=0;
        for (int m=0;m<n;m++)
         {
             if (a[m]->getma()==i)
             {
                dem=1;
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
         if(dem==0) cout<<"Ma nhan vien khong ton tai";
     }
     long luongtb(int i)
     {
         long tong=0;
         for (int j=0;j<n;j++)
            tong=tong+a[j]->luongthang(i);
         return (double)tong/n;
     }
    void tkmnv(int i)
    {
                        int dem=0;
                        cout <<"Nhap ma so nhan vien can tim kiem: ";
                        cin >> i;
                        for(int m=0; m<i; m++)
                        {
                           if (a[m]->getma() == i)
                            {
                                a[m]->xuat();
                                a[m]->luong();
                                dem++;
                            }
                        }
                        if(dem == 0)
                        cout <<"Ma so nhan vien khong co trong danh sach!"<<endl;
    }
    void tkten(string ht)
    {
                        int dem=0;
                        cout <<"Nhap ten nhan vien can tim kiem: ";
                        cin >> ht   ;
                        for(int i=0; i<n; i++)
                        {
                           if (ht.compare(a[i]->getten())==0)
                            {
                                a[i]->xuat();
                                a[i]->luong();
                                dem++;
                            }
                        }
                        if(dem == 0)
                        cout <<"Nhan vien khong co trong danh sach!"<<endl;
    }
    void tksdt(string so)
    {
                        int dem=0;
                        cout <<"Nhap so dien thoai nhan vien can tim kiem: ";
                        cin >> so;
                        for(int m=0; m<n; m++)
                        {
                           if (a[m]->getsdt() == so)
                            {
                                a[m]->xuat();
                                a[m]->luong();
                                dem++;
                            }
                        }
                        if(dem == 0)
                        cout <<"Nhan vien khong co trong danh sach!"<<endl;
    }
    void tklamviec(int x, int y, int z)
    {
                        int dem=0;
                        cout <<"Nhap ngay bat dau lam cua nhan vien can tim kiem: ";
                        cin>>x; cin.ignore();
                        cin>>y; cin.ignore();
                        cin>>z; cin.ignore();
                        for(int m=0; m<n; m++)
                        {
                           if (a[m]->getday() == x && a[m]->getmon() == y && a[m]->getyear() == z)
                            {
                                a[m]->xuat();
                                a[m]->luong();
                                dem++;
                            }
                        }
                        if(dem == 0)
                        cout <<"Nhan vien khong co trong danh sach!"<<endl;
    }
    void thongke(int i)
    {
        int dem=0;
        for (int m=0; m<n; m++)
        {
            if (a[m]->luongthang(i)<luongtb(i))
            {
                a[m]->xuat();
                dem++;
            }
        }
        if (dem==0)
        cout <<"Khong co nhan vien nao co luong thap hon luong trung binh"<<endl;
    }
};
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
        cout<<"6. Tim kiem nhan vien theo ma nhan vien"<<endl;
        cout<<"7. Tim kiem nhan vien theo ho ten"<<endl;
        cout<<"8. Tim kiem nhan vien theo so dien thoai"<<endl;
        cout<<"9. Tim kiem nhan vien theo ngay bat dau lam viec"<<endl;
        cout<<"10. Tinh muc luong trung binh cac nhan vien theo thang"<<endl;
        cout<<"11. Thong ke cac nhan vien co muc luong thap hon muc luong trung binh cac nhan vien theo thang"<<endl;
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
                int m;
                x.tkmnv(m);
                break;
            }
        case 7:
            {
                string m;
                x.tkten(m);
                break;
            }
        case 8:
            {
                string m;
                x.tksdt(m);
                break;
            }
        case 9:
            {
                int v,y,z;
                x.tklamviec(v,y,z);
                break;
            }
        case 10:
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
               cout<<x.luongtb(n);
               break;
            }
        case 11:
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
                x.thongke(n);
               break;
            }
            }


        cout<<endl<<"Ban co muon chon tiep khong?"<<endl;
        cout<<"1. Co"<<endl;
        cout<<"2. Khong"<<endl;
        cout<<"Moi ban nhap lua chon: ";
        cin>>i;
    }
    return 0;
}
