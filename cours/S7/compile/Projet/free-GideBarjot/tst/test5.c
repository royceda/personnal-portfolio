int f(int x) {
  int y;
  y=5;
  if (x==y) { 
    x=x+1; 
    return x;
  } else if (x<y+4) {
    return x+y;
  } 
  else {
    return y;
  }
}

int main(){
  return 0;
}
