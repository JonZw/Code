class PokemonTest
{
  public static void main(String[] args)
  {
    //Erstelle pikatchu
    Pokemon pikatchu;
    pikatchu = new Pokemon("Pikatchu",Type.FIRE);
    //Testen der getter
    System.out.println(pikatchu.get_name()+" "+pikatchu.get_type()+" "+pikatchu.get_number());
    //Erstelle zweites Pokemon
    Pokemon charizard;
    charizard = new Pokemon("Charizard",Type.FIRE);
    //Testen der getter mit zwei existierenden Pokemon
    System.out.println(charizard.get_name()+" "+charizard.get_type()+" "+charizard.get_number());
    //Testen des toString
    System.out.println(pikatchu);
  }
}
