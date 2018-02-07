
class Messages {
  final private String[] data = new String[20];
  private int nbElement;

  void clear() {
    for (int i = 0; i < data.length; i++) {
      if (data[i] == null)
	break;
      data[i] = null;
    }
    nbElement = 0;
  } 

  int size() {
    return nbElement;
  }

  String get(int num) {
    assert num > 0 : "pas de message";
    return data[num - 1];
  }

  String getLast() {
    return get(size());
  }

  void add(String s) {
    data[nbElement++] = s;
  }

  static public void main(String[] argv) {
    Messages m = new Messages();
    
    // test 1
    assert 0 == m.size() : "0";
    assert m.get(1) == null : "null";    
    
    // test 2
    m.add("un");
    m.add("deux");
    m.add("trois");

    assert      3 == m.size() : "3";
    assert "deux"  == m.get(2) : "deux";    
    assert "un"    == m.get(1) : "un";    
    assert "trois" == m.get(3) : "trois";    
    assert    null == m.get(4) : "null 4";    
    assert    null == m.get(10): "null 10";    

    // test 3
    m.clear();

    assert 0 == m.size() : "0";
    assert m.get(1) == null : "null 1";    
    assert m.get(3) == null : "null 3";    
    assert m.get(4) == null : "null 4";    

    assert fin("OK " + m.getClass().getName());
  }

  static private boolean fin(String s) {
    System.out.println(s);
    return true;
  }
}
