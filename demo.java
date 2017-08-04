import java.util.*;
import java.lang.*;

public class demo{

	static { System.load("/home/su/java/demo/jni/demo.so");}

	public  int num=0;

	public String str;


	public demo(){
	
		System.out.println("hello demo!");
	}
	
	public static native demo createdemo();

	public native void show();

	public native String[] get();

	public native void Array(String[] arg);

	public void javashow(String[] argv){

			for(String s:argv)
				System.out.println(s);

	}

	public static void main(String[] argv){


		demo ins=createdemo();
		ins.show();
		System.out.println(ins.num);
		System.out.println(ins.str);


		ins.Array(new String[]{"java","c++","python"});

		ins.javashow(ins.get());

	}
}