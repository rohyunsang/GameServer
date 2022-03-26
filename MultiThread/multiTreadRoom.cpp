class MyGameServer
{
      class Rooom
      {
        CriticalSection m_critSec;
        String m_rooomName;
        List<Player> m_players;
        List<Character> m_characters;
      }
      
      map<PlayerID, shared_ptr<Room> >
        m_roomList;
      String m_serverName;
      
      CriticalSection m_critSec;
}
