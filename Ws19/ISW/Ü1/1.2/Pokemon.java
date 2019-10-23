public class Pokemon
{
  private String _name;
  private Type _type;
  private int _number;
  private static int _nextnumber=0;
  public static void main(String[] args)
  {
    Pokemon pikatchu;
    pikatchu = new Pokemon("Pikatchu",Type.FIRE);
  }
  public Pokemon(String name,Type type)
  {
    this._name=name;  // this spricht _name des Pokemon an, von dem die Methode
                      //aufgerufen wurde
    this._type=type;
    this._number=_nextnumber;
    _nextnumber+=1;
  }
  public String get_name()
  {
    return this._name;
  }
  public Type get_type()
  {
    return this._type;
  }
  public int get_number()
  {
    return this._number;
  }
  public String toString()
  {
    return ("Name: "+this._name+"\nType: "+this._type+"\nNummer: "+this._number);
  }
}
