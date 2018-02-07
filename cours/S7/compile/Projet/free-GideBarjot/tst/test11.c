int f(int x) {
  int y;
  y=5;
  if (x > y) 
    return x;
  else if (x < y)
    return x+y;

  if (x = y)
    return 0;
}

int main(){
  int x = f(3);
  return 0;
}
