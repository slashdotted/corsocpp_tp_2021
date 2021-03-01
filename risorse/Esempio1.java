import java.lang.String;

class Esempio1 {
	public static void fun(String x) {
		x = "Hello world";
	}
	public static void main(String[] args) {
		String s = "hello moon";
		fun(s);
		System.out.println(s);
	}
}
