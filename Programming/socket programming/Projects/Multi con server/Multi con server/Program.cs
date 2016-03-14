﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;


namespace Multi_con_server
{
    class Program
    {
        static Listener l;
        static int counter = 0;
        static List<Socket> sockets;
        static void Main(string[] args)
        {
            l = new Listener(8);
            l.SocketAccepted += new Listener.SocketAcceptedHandler(l_SocketAccepted);
            l.Start();

            sockets = new List<Socket>();

            Console.Read();
        }


        static void l_SocketAccepted(Socket e)
        {
            Console.WriteLine("New Connection: {0}\n{1}\n{2}\n=========",counter, e.RemoteEndPoint, DateTime.Now);
            sockets.Add(e);
            counter++;
        }

    }
}
