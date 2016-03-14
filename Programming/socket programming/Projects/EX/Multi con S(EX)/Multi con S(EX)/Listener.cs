using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace Multi_con_S_EX_
{
    class Listener
    {
        Socket s;
        public bool Listening
        {
            get;
            private set;
        }
        public int Port
        {
            get;
            private set;
        }
        public Listener(int Port)
        {
            this.Port = Port;
            s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        }

        public void Start()
        {
            if (Listening)
                return;
            s.Bind(new IPEndPoint(0, Port));
            s.Listen(0);
            s.BeginAccept(callback, null);
            Listening = true;
        }

        public void Stod()
        {
            if (!Listening)
                return;
            s.Close();
            s.Dispose();
            s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        }

        public void callback(IAsyncResult ar)
        {


        }
    }
}
