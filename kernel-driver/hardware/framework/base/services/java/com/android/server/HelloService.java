package com.android.server;
import android.content.Context;
import android.os.IHelloService;
import android.os.util.Slog;

public class HelloService extends IHelloService.stub{
    private static final String TAG = "HelloService";
    HelloService(){
        init_native();
    }

    public void setVal(int val){
        setval_native(val);
    }

    public int getVal(){
        return getval_native();
    }

    private static native boolean init_native();
    private static native boolean setval_native(int val);
    private static native boolean getval_native();
};
