using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
namespace Multi_con_S_EX_
{
    class Program
    {
        static Listener l;
        static List<Socket> sockets;
        static void Main(string[] args)
        {
            l = new Listener(8);
            l.socketAccepted += new Listener.SocketAcceptedHandler(l_socketAccepted);
            l.Start();
            sockets = new List<Socket>();
            Console.Read();
        }

        static void l_socketAccepted(System.Net.Sockets.Socket e)
        {
            Console.WriteLine("new connection: {0}\n{1}\n========", e.RemoteEndPoint, DateTime.Now);
            sockets.Add(e);
        }
    }
}
