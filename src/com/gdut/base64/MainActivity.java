package com.gdut.base64;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener{

	private Button encode,decode;
	private TextView code;
	private EditText input;
	private base64 mbase64;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		encode = (Button) findViewById(R.id.encode);
		decode = (Button) findViewById(R.id.decode);
		code = (TextView) findViewById(R.id.result);
		input = (EditText) findViewById(R.id.input);
		encode.setOnClickListener(this);
		decode.setOnClickListener(this);
		mbase64 = new base64();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public void onClick(View v) {
		if(v == encode){
			code.setText(mbase64.encode(input.getText().toString()));
		}else if(v == decode){
			code.setText(mbase64.decode(input.getText().toString()));
		}
	}

}
