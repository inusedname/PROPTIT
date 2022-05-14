package test;

class Test
{
    public static void main(String[] args) {
        NhanVien a = new NhanVien();
        a.setAge(20);
        a.setName("Nguyen");
        System.out.println(a.getName()+ " " + a.getAge());
    }
};