// 10727216 李品毅  10727246 劉晉成 
# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <math.h> 
# include <string.h>

using namespace std ;

typedef char Str500[500] ;

int Readint() ;
// 讀字串並且轉成數字 

void Iterative() ;
// 迴圈模式 

void Recursive() ;
// 遞迴模式

void Fibonacci( long long int & preprenum, long long int & prenum, long long int inputnum, int & time ) ; 
// 計算費氏數列的遞迴 

void  Findfactor( long long int & time, long long int currentnum, long long int & runtime ) ; 
// 找因數的遞迴

int main() { // 主程式 
	int mode = 0 ;
	cout << "** Fibonacci Series Generator **" << endl ;
	cout << "* 0. Quit                      *" << endl ;
	cout << "* 1. Iterative generation      *" << endl ;
	cout << "* 2. Recursive generation      *" << endl ;
	cout << "********************************" << endl << endl ;
	cout << "Input a command(0, 1, 2):" ;
	mode = Readint() ; // 讀入 
	while ( mode != 0 ) { // 判斷有沒有結束 
		if ( mode == 1 ) {
			Iterative() ; // 使用者輸入【1】進迴圈模式 
		}
		else if ( mode == 2 ) {  
			Recursive() ; // 使用者輸入【2】進遞迴模式 
		}
		else { // 使用者亂來
			cout << endl << "error command ! Please enter again !" << endl <<endl ; 
		}
		
		system( "pause" ) ; // 畫面暫停 
		system( "CLS" ) ;   // 清空畫面 
	    cout << "** Fibonacci Series Generator **" << endl ;
	    cout << "* 0. Quit                      *" << endl ;
	    cout << "* 1. Iterative generation      *" << endl ;
	    cout << "* 2. Recursive generation      *" << endl ;
	    cout << "********************************" << endl << endl ;
	    cout << "Input a command(0, 1, 2):" ;
	    mode = Readint() ; //跑完之後繼續讀 
	}
	
	if ( mode == 0 ) {  
		cout << "bye bye" << endl ; // 使用者結束說掰掰 
	}
	
	system( "pause" ) ; // 讓畫面停住不然會直接跳走 
	return 0 ;
} // main()

int Readint() { // 讀字串並且轉成數字 
	Str500 input, temp ;
	int num = -1, tempnum = 0 ;
	for ( int i = 0 ; i < strlen( input ) ; i++ ) {
		input[i] = '\0' ;
	} //清空字串 
	
	for ( int i = 0 ; i < strlen( temp ) ; i++ ) {
		temp[i] = '\0' ;
	} //清空字串 
	
	scanf ( "%s", input ) ; // 讀入 	
	for( int i = 0 ; i < strlen( input ) ; i++ ) { // 整個input字串跑一遍 
		if ( input[i] - '0' >= 0 && input[i] - '0' <= 9 ) { // 是數字 
			temp[tempnum] = input[i] ; // 記錄下來 
			tempnum++ ;
			num = atoi( temp ) ; // 字串轉數字 
		}
		else {
			i = 999 ; // 跳出迴圈 
		}
	}
	
	return num ; // 回傳最終的值 
} //  Readint()

void Iterative() { // 迴圈模式 
	cout << "Loop Mode" << endl ;
	long long int inputnum = 0, sqrtnum = 0, anotherfactor = 0 ; 
	long long int preprenum = 0, prenum = 1, currentnum = 0 ;
	int looptime = 0 ;
	cout << "please input a number :" ; 
	inputnum = Readint() ; //  讀入 
	while ( inputnum < 0 || inputnum > 92 ) { // 如果數字超出範圍再讓輸入者重新輸入
    	cout << "please input a number :" ; 
        inputnum = Readint() ;
	}
	
	for ( int i = 1 ; i <= inputnum ; i++ ) { // 設定終點 
	    looptime++ ;
		currentnum = preprenum + prenum ; //  設定費氏數列算到哪了 
		cout << "[ " << i << " ] " << currentnum << " = " ; // 輸出
		preprenum = prenum ;  // 紀錄上一個數字 
		prenum = currentnum ; // 記錄目前數字 
		sqrtnum = sqrt( currentnum ) ; // 現在數字開根號 
  	    long long int runtime = 0 ;
        for ( long long int j = sqrtnum ; j > 0 ; j -= 1) { // 開始找 
    	    runtime++ ;
    	    if ( currentnum % j == 0 ) { // 找到了 
    	 	    anotherfactor = currentnum / j ; // 設定另一個因數 
    		    cout << j << " * " << anotherfactor << " 【loop time: " << runtime << " times.】" << endl ;
    		    j = 0 ; // 跳迴圈 
		    } // 找到了，輸出並跳迴圈 
	    } // 找因數 
	} // 大迴圈跑費氏數列，小迴圈跑因數 
	
	cout << endl << "<Outer loop:   " << looptime << " times>" << endl << endl ; // 總共進幾次費氏迴圈 
} // Iterative()

void Recursive() { // 遞迴模式 
	cout << "Recursion Mode" << endl ;
	long long int preprenum = 0, prenum = 1, inputnum = 0 ;
	cout << "please input a number :" ; 
    inputnum = Readint() ; // 讀入 
    while ( inputnum < 0 || inputnum > 92 ) { // 超過範圍再讀一次 
    	cout << "please input a number :" ; 
        inputnum = Readint() ;
	}
	
	int time = 1 ;
	Fibonacci( preprenum, prenum, inputnum, time ) ; // 召喚遞迴跑費氏以及找因數 
	cout << endl << "<Outer recursion:   " << time - 1 << " times>" << endl << endl ; // 總共跑幾次費氏遞迴，因為time初始是1所以要減1 
} // Recursive()

void Fibonacci( long long int & preprenum, long long int & prenum, long long int inputnum, int & time ) { // 計算費氏數列的遞迴 
	if ( time > inputnum ) {
		; 
	} // 跑完了 
	else {
		long long int currentnum = preprenum + prenum ; //  設定費氏數列算到哪了 
		cout << "[ " << time << " ] " << currentnum << " = ";
		preprenum = prenum ; // 記錄前一個數 
		prenum = currentnum ; // 紀錄目前的數 
		long long int sqrtnum = sqrt( currentnum ) ; // 開根號 
  	    long long int runtime = 0 ;
  	    time++ ;
  	    Findfactor( sqrtnum, currentnum, runtime ) ; // 開始找因數 
  	    Fibonacci( preprenum, prenum, inputnum, time ) ; // 召喚自己 
	}
} // Fibonacci()

void  Findfactor( long long int & time, long long int currentnum, long long int & runtime ) { // 找因數的遞迴 
	if ( time == 0 ) {
		; // 跑完了 
	}
	else {
		runtime++ ;
		if ( runtime > 10000000 ) {   
    		cout << " 【recursion time: more than   10000000 times.】" << endl ;
    		time = 1 ;  
		} // 超過 10000000 次了 
		else if ( currentnum % time == 0 ) { // 找到了 
			long long int anotherfactor = currentnum / time ; // 設定另一個因數 
    		cout << time << " * " << anotherfactor << " 【recursion time: " << runtime << " times.】" << endl ;
    		time = 1 ;
		} // 找到並跳遞迴 
		
		time-- ; // 往前找 
		Findfactor( time, currentnum, runtime ) ; // 召喚自己 
	}
} // Findfactor()
