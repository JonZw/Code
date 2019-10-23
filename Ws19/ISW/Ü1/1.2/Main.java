class Main
{
  public static void main(String[] args)
  {
    Pokemon pikatchu;
    pikatchu = new Pokemon("Pikatchu",Type.FIRE);
    System.out.println(pikatchu.get_name()+" "+pikatchu.get_type()+" "+pikatchu.get_number());
    Pokemon charizard;
    charizard = new Pokemon("Charizard",Type.FIRE);
    System.out.println(charizard.get_name()+" "+charizard.get_type()+" "+charizard.get_number());
    System.out.println(pikatchu);
  }
}
