public class IPS extends NF {
    private RC nowRC;
    private String automataState;
    public IPS(RC newRC)
    {
        nowRC = newRC;
    }
    private String initAutomataState()
    {
        return "";
    }
    private Byte popNextByte(String payload)
    {
        return 'b';
    }
    private String process(Byte b, String automataState)
    {
        return automataState;
    }
    public void ProcessPacket(Packet P) {
        String tupleof5 = P.Get("5-tuple");
        String status = P.Get("status");
        String payload = P.Get("payload");
        if (status.equals("SYN")){
            automataState = initAutomataState();
            nowRC.WriteRC(tupleof5, automataState);
        } else {
            automataState = nowRC.ReadRC(tupleof5);
            Byte b;
            while ((b = popNextByte(payload)).equals('a'))
            {
                automataState = process(b, automataState);
            }
            nowRC.WriteRC(tupleof5, automataState);
            PacketSender.sendPacket(P);
        }
    }
}
