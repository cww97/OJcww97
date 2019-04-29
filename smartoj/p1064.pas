program cx;//ÐüÒÉ³ÌÐò
const p=100007;
var i,num,top:longint;
    st:string;
    ans:array[0..1000000]of longint;
    a:array[0..100]of longint;
    v:array[0..p-1]of boolean;
    ok:boolean;

function hash(x:longint):longint;
var i,lo:longint;
begin
  lo:=(10*trunc(ln(x))+x div 10-x mod 10) mod p;
  exit(lo);
end;

procedure find(x:longint);
var i,j,l,temp,max,min:longint;
    st,ch:string;
    //ch:char;
begin
  if ok then exit;
  if v[hash(x)] then
    begin
      for i:=1 to top do if ans[i]=x then break;
      for j:=i to top-1 do write(ans[j],' ');
      writeln(ans[top]);
      ok:=true;
    end;

  v[hash(x)]:=true;
  inc(top);
  ans[top]:=x;

  str(x,st);                                      //sort
  l:=length(st);
  for i:=1 to l do val(st[i],a[i]);
  for i:=1 to l-1 do
    for j:=i+1 to l do
      if a[i]>a[j] then
       begin temp:=a[i]; a[i]:=a[j]; a[j]:=temp; end;

  st:='';
  for i:=1 to l do
    begin
      str(a[i],ch);
      st:=st+ch;
    end;
  val(st,min);

  st:='';
  for i:=l downto 1 do
    begin
      str(a[i],ch);
      st:=st+ch;
    end;
  val(st,max);
  find(max-min);
end;

begin
  assign(input,'ghk.in');
  assign(output,'ghk.out');
  reset(input);
  rewrite(output);
  while not seekeof do
    begin
      fillchar(v,sizeof(v),0);
      fillchar(ans,sizeof(ans),0);
      top:=0;
      ok:=false;
      readln(num);
      find(num);
    end;
  close(input);
  close(output);
end.
