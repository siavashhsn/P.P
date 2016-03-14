namespace Database_Project__store_
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.exit_Btn = new System.Windows.Forms.Button();
            this.login_Btn = new System.Windows.Forms.Button();
            this.username_TextBox = new System.Windows.Forms.TextBox();
            this.password_Textbox = new System.Windows.Forms.TextBox();
            this.Username = new System.Windows.Forms.Label();
            this.Password = new System.Windows.Forms.Label();
            this.branchID_textBox = new System.Windows.Forms.TextBox();
            this.storeID_textBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // exit_Btn
            // 
            this.exit_Btn.Location = new System.Drawing.Point(98, 206);
            this.exit_Btn.Name = "exit_Btn";
            this.exit_Btn.Size = new System.Drawing.Size(103, 40);
            this.exit_Btn.TabIndex = 0;
            this.exit_Btn.Text = "Exit";
            this.exit_Btn.UseVisualStyleBackColor = true;
            this.exit_Btn.Click += new System.EventHandler(this.exit_Btn_Click);
            // 
            // login_Btn
            // 
            this.login_Btn.Location = new System.Drawing.Point(234, 206);
            this.login_Btn.Name = "login_Btn";
            this.login_Btn.Size = new System.Drawing.Size(103, 40);
            this.login_Btn.TabIndex = 1;
            this.login_Btn.Text = "Log in";
            this.login_Btn.UseVisualStyleBackColor = true;
            this.login_Btn.Click += new System.EventHandler(this.login_Btn_Click);
            // 
            // username_TextBox
            // 
            this.username_TextBox.AcceptsTab = true;
            this.username_TextBox.Location = new System.Drawing.Point(98, 105);
            this.username_TextBox.Name = "username_TextBox";
            this.username_TextBox.Size = new System.Drawing.Size(239, 22);
            this.username_TextBox.TabIndex = 2;
            // 
            // password_Textbox
            // 
            this.password_Textbox.AcceptsTab = true;
            this.password_Textbox.Location = new System.Drawing.Point(98, 154);
            this.password_Textbox.Name = "password_Textbox";
            this.password_Textbox.Size = new System.Drawing.Size(239, 22);
            this.password_Textbox.TabIndex = 3;
            // 
            // Username
            // 
            this.Username.AutoSize = true;
            this.Username.Location = new System.Drawing.Point(15, 108);
            this.Username.Name = "Username";
            this.Username.Size = new System.Drawing.Size(73, 17);
            this.Username.TabIndex = 4;
            this.Username.Text = "Username";
            // 
            // Password
            // 
            this.Password.AutoSize = true;
            this.Password.Location = new System.Drawing.Point(19, 157);
            this.Password.Name = "Password";
            this.Password.Size = new System.Drawing.Size(69, 17);
            this.Password.TabIndex = 5;
            this.Password.Text = "Password";
            // 
            // branchID_textBox
            // 
            this.branchID_textBox.Location = new System.Drawing.Point(98, 57);
            this.branchID_textBox.Name = "branchID_textBox";
            this.branchID_textBox.Size = new System.Drawing.Size(239, 22);
            this.branchID_textBox.TabIndex = 6;
            // 
            // storeID_textBox
            // 
            this.storeID_textBox.Location = new System.Drawing.Point(98, 12);
            this.storeID_textBox.Name = "storeID_textBox";
            this.storeID_textBox.Size = new System.Drawing.Size(239, 22);
            this.storeID_textBox.TabIndex = 7;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 17);
            this.label1.TabIndex = 8;
            this.label1.Text = "StoreID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 17);
            this.label2.TabIndex = 9;
            this.label2.Text = "BranchID";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(372, 271);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.storeID_textBox);
            this.Controls.Add(this.branchID_textBox);
            this.Controls.Add(this.Password);
            this.Controls.Add(this.Username);
            this.Controls.Add(this.password_Textbox);
            this.Controls.Add(this.username_TextBox);
            this.Controls.Add(this.login_Btn);
            this.Controls.Add(this.exit_Btn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button exit_Btn;
        private System.Windows.Forms.Button login_Btn;
        private System.Windows.Forms.TextBox username_TextBox;
        private System.Windows.Forms.TextBox password_Textbox;
        private System.Windows.Forms.Label Username;
        private System.Windows.Forms.Label Password;
        private System.Windows.Forms.TextBox branchID_textBox;
        private System.Windows.Forms.TextBox storeID_textBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

