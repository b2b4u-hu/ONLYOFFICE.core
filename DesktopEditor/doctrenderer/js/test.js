
var MyGraphics = new CNativeGraphics();

// Задаём размеры холста
MyGraphics.init(null, 200, 149, 52.9167, 39.4229);

// Проверка FillTextCode
MyGraphics.CoordTransformOffset(-187.936, -66.5134);
MyGraphics.transform(1, 0, 0, 1, 0, 0);
MyGraphics.SetIntegerGrid(false);
MyGraphics.transform(1, 0, 0, 1, 50.2979, 18.1354);
MyGraphics.p_width(1058.31);
MyGraphics._s();
MyGraphics._m(0, 0);
MyGraphics._l(51.8583, 0);
MyGraphics._l(51.8583, 38.3646);
MyGraphics._l(0, 38.3646);
MyGraphics._z();
MyGraphics.p_color(67, 115, 158, 255);
MyGraphics.b_color1(91, 155, 213, 255);
MyGraphics.drawpath(256 + 1);
MyGraphics._e();
MyGraphics.p_dash(null);

MyGraphics.SetIntegerGrid(false);
MyGraphics.transform(1, 0, 0, 1, 50.2979, 18.1354);
MyGraphics._s();
MyGraphics._m(-1.6, 0.199153);
MyGraphics._l(51.8583, 0.199153);
MyGraphics._l(51.8583, 36.5654);
MyGraphics._l(-1.6, 36.5654);
MyGraphics._l(-1.6, 0.199153);
MyGraphics.SetIntegerGrid(false);
MyGraphics.transform(1, 0, 0, 1, 53.3671, 32.988);
MyGraphics.b_color1(0, 0, 0, 255);
MyGraphics.p_color(0, 0, 0, 255);
MyGraphics.SetFont({FontFamily : {Name : "Arial", Index : -1}, FontSize : 16, Italic : true, Bold : true});
MyGraphics.FillTextCode(12.2943, 3.63992, 72);
MyGraphics.FillTextCode(15.0967, 3.63992, 101);
MyGraphics.FillTextCode(17.2548, 3.63992, 108);
MyGraphics.FillTextCode(18.117,  3.63992, 108);
MyGraphics.FillTextCode(18.9791, 3.63992, 111);
MyGraphics.FillTextCode(22.2153, 3.63992, 87);
MyGraphics.FillTextCode(25.8779, 3.63992, 111);
MyGraphics.FillTextCode(28.0361, 3.63992, 114);
MyGraphics.FillTextCode(29.3283, 3.63992, 108);
MyGraphics.FillTextCode(30.1904, 3.63992, 100);
MyGraphics.FillTextCode(32.3486, 3.63992, 33);
MyGraphics.SetIntegerGrid(true);
MyGraphics.reset();
MyGraphics.toDataURL("image/png");

// Рисование шейпа с треугольником
/*
MyGraphics.SetIntegerGrid(false);
MyGraphics.transform(1, 0, 0, 1, 0, 0);//0.617492, -0.786577, 0.786577, 0.617492, 123.177, 40.1987);
MyGraphics.ArrayPoints = null;
MyGraphics.p_width(1058.31);
MyGraphics._s();
MyGraphics._m(0, 39.1583);
MyGraphics._l(25.6646, 0);
MyGraphics._l(51.3292, 39.1583);
MyGraphics._z();
MyGraphics.p_color(0, 176, 80, 255);
MyGraphics.b_color1(255, 0, 0, 255);
MyGraphics.drawpath(256 + 1);
MyGraphics._e();
MyGraphics.p_dash(null);
MyGraphics.SetIntegerGrid(true);
MyGraphics.reset();
MyGraphics.toDataURL("image/png");

// Рисование картинки с помощью brush
MyGraphics.SetIntegerGrid(false);
MyGraphics.transform(1, 0, 0, 1, 0, 0);
MyGraphics.ArrayPoints = null;
MyGraphics.put_TextureBoundsEnabled(true);
MyGraphics.put_TextureBounds(0, 0, 66.1458, 102.923);
MyGraphics._s();
MyGraphics._m(0, 0);
MyGraphics._l(66.1458, 0);
MyGraphics._l(66.1458, 102.923);
MyGraphics._l(0, 102.923);
MyGraphics._z();
MyGraphics.put_brushTexture("image3.jpg");
MyGraphics.put_BrushTextureAlpha(0);
MyGraphics.drawpath(256);
MyGraphics._e();
MyGraphics.put_TextureBoundsEnabled(false);
MyGraphics.p_dash(null);
MyGraphics.reset();
MyGraphics.SetIntegerGrid(true);
MyGraphics.toDataURL("image/png");

MyGraphics.put_GlobalAlpha(true, 0.5);

// Рисуем желтый квадрат с красной пунктирной обводкой и толщиной 2
MyGraphics.p_color(255, 0, 0, 255);

var PenColor = MyGraphics.GetPenColor();
MyGraphics.p_color(PenColor.R, PenColor.G, PenColor.B, PenColor.A);

MyGraphics.p_width(2);
MyGraphics.p_dash([5, 5]);
MyGraphics.b_color1(255, 255, 0, 255);

var BrushColor = MyGraphics.GetBrushColor();
MyGraphics.b_color1(BrushColor.R, BrushColor.G, BrushColor.B, BrushColor.A);

MyGraphics._s();
MyGraphics._m(10, 10);
MyGraphics._l(100, 10);
MyGraphics._l(100, 100);
MyGraphics._l(10, 100);
MyGraphics._z();
MyGraphics.df();
MyGraphics.ds();

// Поварачиваем плоскость рисования
MyGraphics.transform(1, 0.5, 0.1, 1, 0, 0);

// Рисуем розовый квадрат с бардовой сплошной обводкой и толщиной 1
MyGraphics.p_color(111, 0, 53, 255);
MyGraphics.p_width(1);
MyGraphics.p_dash();
MyGraphics.b_color1(222, 155, 176, 255);
MyGraphics.rect(75, 50, 100, 100)
MyGraphics.df();
MyGraphics.ds();

// Восстанавливаем плоскость рисования до нормальной и убираем полупрозрачность
MyGraphics.reset();
MyGraphics.put_GlobalAlpha(true, 1);

MyGraphics.SetFont({FontFamily : {Name : "Arial", Index : -1}, FontSize : 16, Italic : true, Bold : true});
MyGraphics.FillText(10, 110, "A");
MyGraphics.tg("A", 10, 130);
MyGraphics.t("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10, 230, false);

// Рисуем кривую с одной контрольной точкой
MyGraphics.b_color1(66, 255, 158, 255);
MyGraphics._s();
MyGraphics._m(10, 10);
MyGraphics._c2(100, 50, 10, 100);
MyGraphics._z();
MyGraphics.df();
MyGraphics.ds();

// Отсекаем область рисования последним контруром и снова полупрозрачность
MyGraphics.clip();
MyGraphics.put_GlobalAlpha(true, 0.5);

// Рисуем кривую с двумя контрольными точками
MyGraphics.b_color1(121, 160, 255, 255);
MyGraphics._s();
MyGraphics._m(100, 10);
MyGraphics._c(10, 10, 10, 100, 100, 100);
MyGraphics._z();
MyGraphics.df();
MyGraphics.ds();

// Восстанавливаем область рисования и поворачиваем плоскость рисования
MyGraphics.restore();
MyGraphics.transform3({ sx : 1, shy : 0.5, shx : 0.1, sy : 1, tx : 0, ty : 0 }, false);

// Рисуем изображение из файла
MyGraphics.drawImage2("image1.png", 95, 76, 60, 48, 0, null);

MyGraphics.reset();
MyGraphics.DrawStringASCII("Times New Roman", 16, false, false, "Test TEXT TEXT TEXT TEXT", 10, 210, false);
MyGraphics.DrawHeaderEdit(10);
MyGraphics.DrawFooterEdit(250);
MyGraphics.DrawLockParagraph(null, 10, 110, 200);
MyGraphics.DrawLockObjectRect(null, 20, 110, 90, 90);
MyGraphics.DrawEmptyTableLine(10, 110, 110, 210);
MyGraphics.DrawSpellingLine(120, 10, 100, 5);
MyGraphics.drawHorLine(1, 130, 10, 110, 10);
MyGraphics.drawVerLine(1, 30, 110, 200, 10);
MyGraphics.drawHorLineExt(1, 170, 20, 110, 5, 20, 0);

MyGraphics.p_color(111, 0, 53, 255);
MyGraphics.p_width(3);
MyGraphics.b_color1(222, 155, 176, 255);
MyGraphics._s();
MyGraphics.TableRect(110, 10, 90, 90);
MyGraphics._z();

// Рисует замыкание со второй до предпоследней точки
MyGraphics.DrawPolygon({Points : [{X : 10, Y : 10}, {X : 20, Y : 20}, {X : 20, Y : 30}, {X : 10, Y : 40}, {X : 0, Y : 30}]}, 3, 0);

MyGraphics.DrawFootnoteRect(30, 30, 90, 90);

MyGraphics.b_color1(255, 0, 0, 255);
MyGraphics._s();
MyGraphics.AddClipRect(210, 10, 50, 50);
MyGraphics.ds();
MyGraphics._z();
MyGraphics.RemoveClipRect();

MyGraphics.SetClip({ x : 210, y : 70, w : 50, h : 50});
MyGraphics.RemoveClip();

var imageBase64 = MyGraphics.toDataURL("png");
MyGraphics.save();
MyGraphics.put_brushTexture("pathtobrush", 0);
MyGraphics.put_BrushTextureAlpha(255);
MyGraphics.put_BrushGradient({colors : [{R : 255, G : 255, B : 255, A : 255}, {R : 255, G : 255, B : 255, A : 255}, {R : 255, G : 255, B : 255, A : 255}, {R : 255, G : 255, B : 255, A : 255}, {R : 255, G : 255, B : 255, A : 255}, {R : 255, G : 255, B : 255, A : 255}]}, {x0 : 0, y0 : 0, x1 : 0, y1 : 0, r0 : 0, r1 : 0}, null);
var x = MyGraphics.TransformPointX(10, 10);
var y = MyGraphics.TransformPointX(10, 10);
MyGraphics.put_LineJoin(5);
var join = MyGraphics.get_LineJoin();
MyGraphics.put_TextureBounds(10, 10, 100, 100);
MyGraphics.GetlineWidth();
*/
