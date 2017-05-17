module ALU(out, c_out, in1, in2, c_in, op, clk, reset);

input [3:0] in1, in2;
input [8*3:0]  op;
input c_in, clk, reset;

output reg [3:0] out;
output reg c_out;

reg z = 1'b0;

always @(posedge clk, op, reset)
begin
    if(reset)
        begin
        out = 4'b0000;
        c_out = 1'b0;
        end
	else
	begin
	case(op)
		"&"   : out = in1 & in2;
		"|"   : out = in1 | in2;
		"^"   : out = in1 ^ in2;
		"~"   : out = ~in1;
		"+"   : {c_out,out} = in1 + in2 + c_in;
		"-"   : {c_out,out} = in1 - in2;
		"+1"  : {c_out,out} = in1 + 1;
		"-1"  : {c_out,out} = in1 - 1;
		"2's" : out = ~in1 + 1;      // 2's complement
		"LSR" : out = in1 >> 1; // Logical shift to right 
		"LSL" : out = in1 << 1; // Logical shift to left
		"ASR" : out = in1 >>> 1; //Arithmetic shift right
		"ASL" : out = in1 <<< 1;
		"RR"  : out = {in1[0], in1[3:1]}; //Rotate to right
		"RL"  : out = {in1[2:0], in1[3]}; //Rotate to left
		"RRC" : {c_out,out} = {in1[0], c_in, in1[3:1]};   //Rotate with carry to right
		"RLC" : {c_out,out} = {in1[3], in1[2:0], c_in};   //Rotate with carry to left
	endcase
	end
end
endmodule



module top;
reg[3:0] In1, In2;
reg [8*3:0] op;
reg C_in, Reset, Clk;

wire C_out;
wire[3:0] out;

ALU alu(out ,C_out , In1, In2,  C_in,  op, Clk, Reset);

initial 
begin
    $monitor("%b %S  %b == %b            C_out : %b" , In1, op, In2, out, C_out);
    Clk = 1'b0;
    forever #10 Clk = ~Clk;
end

initial 
begin
    In1 = 4'b1101;
    In2 = 4'b1011;
    C_in = 1'b0;
    Reset = 1'b0;
    
    //Arithmetic
    #10 op = "+";
	#10 op = "-";
	#10 op = "+1";
	#10 op = "-1";
    
    //Logical
	#10 op = "&";
	#10 op = "|";
	#10 op = "^";
	#10 op = "~";
	
	//Shift
	#10 op = "2's"; //2's complement
	#10 op = "LSR"; //Logical shift to right 
	#10 op = "LSL"; //Logical shift to left
	#10 op = "ASR"; //Arithmetic shift right
	#10 op = "ASL"; //Arithmetic shift left
	#10 op = "RR";  //Rotate to right
	#10 op = "RL";  //Rotate to left
	#10 op = "RRC"; //Rotate right with carry
	#10 op = "RLC"; //Rotate left with carry
end

initial 
begin
   
    #4000 $finish();
end

endmodule