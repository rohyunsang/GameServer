class MyGameServer
{
    class Room
    {
      String m_roomName;
      List<Player> m_players;
      List<Character> m-characters;
    }
    
    map<PlayerID, shared_ptr<Room> >
      m_roomList;
    String m_serverName;
}
