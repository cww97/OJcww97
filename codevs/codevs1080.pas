program cx;
const hk:array[1..30]of longint=(2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824);
var i,n,m,BTM,x,y,z:longint;
    a:array[0..500000]of longint;

procedure change(x,d:longint);
begin
  x:=x+BTM;
  repeat
    a[x]:=a[x]+d;
    x:=x >> 1 ;
  until x=0;
end;

function query(l,r:longint):longint;
var ans:longint;
begin
  ans:=0;
  l:=l+BTM-1; r:=r+BTM+1;
  while not(l xor r=1) do
    begin
      if l and 1=0 then inc(ans,a[l xor 1]);
      if r and 1=1 then inc(ans,a[r xor 1]);
      l:=l >> 1; r:=r >> 1;
    end;
  exit(ans);
end;

begin
  //assign(input, 'hk.in');  reset(input);
  //assign(output,'hk.out'); rewrite(output);
  read(n);
  BTM:=1;
  while BTM<=n do BTM:=BTM << 1 ;
  for i:=1 to 30 do if hk[i]=n then BTM:=BTM >> 1;
  dec(BTM);
  for i:=1 to n do read(a[i+BTM]);
  for i:=BTM-1 downto 1 do a[i]:=a[i << 1]+a[i << 1 xor 1];
  read(m);
  for i:=1 to m do
    begin
      read(x,y,z);
      if x=1 then change(y,z)
        else writeln(query(y,z));
    end;
  //close(input);
  //close(output);
end.
