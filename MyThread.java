import java.util.*;

public class MyThread{


	static { System.load("/home/su/java/demo/jni/MyThread.so");}

	public static native void init();

	public static native void start(int num, int every);

	public static native void free();


	public static void main(String[] argv){

		init();

		System.out.println("Thread num:every");
		
		Scanner sc=new Scanner(System.in);

		int num = sc.nextInt();

		int every=sc.nextInt();

		start(num,every);
		
	}
}