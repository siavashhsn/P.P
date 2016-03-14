using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace Multi_con_client
{
    class Program
    {
        static void Main(string[] args)
        {
            Socket sok = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            sok.Connect("127.0.0.1", 8);
            sok.Close();
            sok.Dispose();
        }
    }
}
