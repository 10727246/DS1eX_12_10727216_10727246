// 10727216 ���~��  10727246 �B�ʦ� 
# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <math.h> 
# include <string.h>

using namespace std ;

typedef char Str500[500] ;

int Readint() ;
// Ū�r��åB�ন�Ʀr 

void Iterative() ;
// �j��Ҧ� 

void Recursive() ;
// ���j�Ҧ�

void Fibonacci( long long int & preprenum, long long int & prenum, long long int inputnum, int & time ) ; 
// �p��O��ƦC�����j 

void  Findfactor( long long int & time, long long int currentnum, long long int & runtime ) ; 
// ��]�ƪ����j

int main() { // �D�{�� 
	int mode = 0 ;
	cout << "** Fibonacci Series Generator **" << endl ;
	cout << "* 0. Quit                      *" << endl ;
	cout << "* 1. Iterative generation      *" << endl ;
	cout << "* 2. Recursive generation      *" << endl ;
	cout << "********************************" << endl << endl ;
	cout << "Input a command(0, 1, 2):" ;
	mode = Readint() ; // Ū�J 
	while ( mode != 0 ) { // �P�_���S������ 
		if ( mode == 1 ) {
			Iterative() ; // �ϥΪ̿�J�i1�j�i�j��Ҧ� 
		}
		else if ( mode == 2 ) {  
			Recursive() ; // �ϥΪ̿�J�i2�j�i���j�Ҧ� 
		}
		else { // �ϥΪ̶è�
			cout << endl << "error command ! Please enter again !" << endl <<endl ; 
		}
		
		system( "pause" ) ; // �e���Ȱ� 
		system( "CLS" ) ;   // �M�ŵe�� 
	    cout << "** Fibonacci Series Generator **" << endl ;
	    cout << "* 0. Quit                      *" << endl ;
	    cout << "* 1. Iterative generation      *" << endl ;
	    cout << "* 2. Recursive generation      *" << endl ;
	    cout << "********************************" << endl << endl ;
	    cout << "Input a command(0, 1, 2):" ;
	    mode = Readint() ; //�]�������~��Ū 
	}
	
	if ( mode == 0 ) {  
		cout << "bye bye" << endl ; // �ϥΪ̵������T�T 
	}
	
	system( "pause" ) ; // ���e�������M�|�������� 
	return 0 ;
} // main()

int Readint() { // Ū�r��åB�ন�Ʀr 
	Str500 input, temp ;
	int num = -1, tempnum = 0 ;
	for ( int i = 0 ; i < strlen( input ) ; i++ ) {
		input[i] = '\0' ;
	} //�M�Ŧr�� 
	
	for ( int i = 0 ; i < strlen( temp ) ; i++ ) {
		temp[i] = '\0' ;
	} //�M�Ŧr�� 
	
	scanf ( "%s", input ) ; // Ū�J 	
	for( int i = 0 ; i < strlen( input ) ; i++ ) { // ���input�r��]�@�M 
		if ( input[i] - '0' >= 0 && input[i] - '0' <= 9 ) { // �O�Ʀr 
			temp[tempnum] = input[i] ; // �O���U�� 
			tempnum++ ;
			num = atoi( temp ) ; // �r����Ʀr 
		}
		else {
			i = 999 ; // ���X�j�� 
		}
	}
	
	return num ; // �^�ǳ̲ת��� 
} //  Readint()

void Iterative() { // �j��Ҧ� 
	cout << "Loop Mode" << endl ;
	long long int inputnum = 0, sqrtnum = 0, anotherfactor = 0 ; 
	long long int preprenum = 0, prenum = 1, currentnum = 0 ;
	int looptime = 0 ;
	cout << "please input a number :" ; 
	inputnum = Readint() ; //  Ū�J 
	while ( inputnum < 0 || inputnum > 92 ) { // �p�G�Ʀr�W�X�d��A�Ӥ@�� 
    	cout << "please input a number :" ; 
        inputnum = Readint() ;
	}
	
	for ( int i = 1 ; i <= inputnum ; i++ ) { // �]�w���I 
	    looptime++ ;
		currentnum = preprenum + prenum ; //  �]�w�O��ƦC�����F 
		cout << "[ " << i << " ] " << currentnum << " = " ;
		preprenum = prenum ;  // �����W�@�ӼƦr 
		prenum = currentnum ; // �O���ثe�Ʀr 
		sqrtnum = sqrt( currentnum ) ; // �{�b�Ʀr�}�ڸ� 
  	    long long int runtime = 0 ;
        for ( long long int j = sqrtnum ; j > 0 ; j -= 1) { // �}�l�� 
    	    runtime++ ;
    	    if ( currentnum % j == 0 ) { // ���F 
    	 	    anotherfactor = currentnum / j ; // �]�w�t�@�Ӧ]�� 
    		    cout << j << " * " << anotherfactor << " �iloop time: " << runtime << " times.�j" << endl ;
    		    j = 0 ; // ���j�� 
		    } // ���F�A��X�ø��j�� 
	    } // ��]�� 
	} // �j�j��]�O��ƦC�A�p�j��]�]�� 
	
	cout << endl << "<Outer loop:   " << looptime << " times>" << endl << endl ; // �`�@�i�X���O��j�� 
} // Iterative()

void Recursive() { // ���j�Ҧ� 
	cout << "Recursion Mode" << endl ;
	long long int preprenum = 0, prenum = 1, inputnum = 0 ;
	cout << "please input a number :" ; 
    inputnum = Readint() ; // Ū�J 
    while ( inputnum < 0 || inputnum > 92 ) { // �W�L�d��AŪ�@�� 
    	cout << "please input a number :" ; 
        inputnum = Readint() ;
	}
	
	int time = 1 ;
	Fibonacci( preprenum, prenum, inputnum, time ) ; // �l�껼�j�]�O��H�Χ�]�� 
	cout << endl << "<Outer recursion:   " << time - 1 << " times>" << endl << endl ; // �`�@�]�X���O�󻼰j�A�]��time��l�O1�ҥH�n��1 
} // Recursive()

void Fibonacci( long long int & preprenum, long long int & prenum, long long int inputnum, int & time ) { // �p��O��ƦC�����j 
	if ( time > inputnum ) {
		; 
	} // �]���F 
	else {
		long long int currentnum = preprenum + prenum ; //  �]�w�O��ƦC�����F 
		cout << "[ " << time << " ] " << currentnum << " = ";
		preprenum = prenum ; // �O���e�@�Ӽ� 
		prenum = currentnum ; // �����ثe���� 
		long long int sqrtnum = sqrt( currentnum ) ; // �}�ڸ� 
  	    long long int runtime = 0 ;
  	    time++ ;
  	    Findfactor( sqrtnum, currentnum, runtime ) ; // �}�l��]�� 
  	    Fibonacci( preprenum, prenum, inputnum, time ) ; // �l��ۤv 
	}
} // Fibonacci()

void  Findfactor( long long int & time, long long int currentnum, long long int & runtime ) { // ��]�ƪ����j 
	if ( time == 0 ) {
		; // �]���F 
	}
	else {
		runtime++ ;
		if ( runtime > 10000000 ) {   
    		cout << " �irecursion time: more than   10000000 times.�j" << endl ;
    		time = 1 ;  
		} // �W�L 10000000 ���F 
		else if ( currentnum % time == 0 ) { // ���F 
			long long int anotherfactor = currentnum / time ; // �]�w�t�@�Ӧ]�� 
    		cout << time << " * " << anotherfactor << " �irecursion time: " << runtime << " times.�j" << endl ;
    		time = 1 ;
		} // ���ø����j 
		
		time-- ; // ���e�� 
		Findfactor( time, currentnum, runtime ) ; // �l��ۤv 
	}
} // Findfactor()
