package tec;

public class TecInvalidException extends Exception {

    TecInvalidException() {
	super(); 
    }
    TecInvalidException(String s) {
	super(s); 
    }
    TecInvalidException(String s, Throwable cause) {
	super(s, cause); 
    }
}
