package com.gdut.base64;

public class base64 {

	static{
		System.loadLibrary("base64");
	}
	
	private native String base64encode(String str);
	private native String base64decode(String str);
	
	public String encode(String str){
		return base64encode(str);
	}
	
	public String decode(String str){
		return base64decode(str);
	}
}
