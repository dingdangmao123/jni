import java.util.*;

public class MyThread{
	static { System.load("/home/su/java/demo/jni/MyThread.so");}

	public static native void init();

	public static native void start(int num, int every);

	public static native void free();


	public static void main(String[] argv){

		init();

		Scanner sc=new Scanner(System.in);

		int num = sc.nextInt();

		int every=sc.nextInt();

		start(num,every);

		try{

			Thread.sleep(10000);

		}catch(Exception e){

				System.out.println(e.toString());

		}finally{

			free();
		}
		
	

	}
}