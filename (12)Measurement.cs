using System;

class ShapeCalculator
{
    static void Main()
    {
        Console.WriteLine("請輸入座標 (x, y)，每行一個座標，輸入空行結束：");

        // 儲存輸入座標的列表
        var coordinates = new System.Collections.Generic.List<Tuple<double, double>>();
        string input;

        // 讀取座標輸入，直到輸入空行為止
        while (!string.IsNullOrWhiteSpace(input = Console.ReadLine()))
        {
            string[] parts = input.Split(' ');
            if (parts.Length == 2 && double.TryParse(parts[0], out double x) && double.TryParse(parts[1], out double y))
            {
                coordinates.Add(Tuple.Create(x, y));
            }
            else
            {
                Console.WriteLine("無效的座標格式，請輸入有效的 (x, y) 座標。");
            }
        }
        coordinates = SortClockwise(coordinates);
        // 判斷形狀
        string shape = DetermineShape(coordinates.Count);

        // 計算面積和周長
        double area = 0;
        double perimeter = 0;

        switch (shape)
        {
            case "Line":
                // 線段，只計算長度
                perimeter = CalculateLinePerimeter(coordinates);
                break;

            case "Triangle":
                // 三角形，計算面積和周長
                area = CalculateTriangleArea(coordinates);
                perimeter = CalculatePerimeter(coordinates);
                break;

            case "Rectangle":
                // 矩形，計算面積和周長
                area = CalculateRectangleArea(coordinates);
                perimeter = CalculatePerimeter(coordinates);
                break;

            case "Pentagon":
                // 五邊形，計算面積和周長
                area = CalculatePentagonArea(coordinates);
                perimeter = CalculatePerimeter(coordinates);
                break;  

            default:
                Console.WriteLine("無法確定形狀");
                return;
        }

        // 顯示結果
        Console.WriteLine($"形狀: {shape}");
        Console.WriteLine($"面積: {area}");
        Console.WriteLine($"周長: {perimeter}");
    }
    static List<Tuple<double, double>> SortClockwise(List<Tuple<double, double>> coordinates)
    {
        // 找到最左下角的點作為起始點
        Tuple<double, double> start = coordinates[0];
        foreach (var point in coordinates)
        {
            if (point.Item2 < start.Item2 || (point.Item2 == start.Item2 && point.Item1 < start.Item1))
            {
                start = point;
            }
        }

        // 使用外積排序座標
        coordinates.Sort((p1, p2) => CompareByCrossProduct(start, p1, p2));

        return coordinates;
    }

    static int CompareByCrossProduct(Tuple<double, double> basePoint, Tuple<double, double> p1, Tuple<double, double> p2)
    {
        double crossProduct = (p1.Item1 - basePoint.Item1) * (p2.Item2 - basePoint.Item2) -
                              (p2.Item1 - basePoint.Item1) * (p1.Item2 - basePoint.Item2);

        if (crossProduct > 0)
        {
            return -1; // p1 在 p2 的逆時針方向
        }
        else if (crossProduct < 0)
        {
            return 1; // p1 在 p2 的順時針方向
        }
        else
        {
            // 如果兩點共線，距離較小的排在前面
            double distance1 = CalculateDistance(basePoint, p1);
            double distance2 = CalculateDistance(basePoint, p2);

            return distance1.CompareTo(distance2);
        }
    }
    static string DetermineShape(int coordinateCount)
    {
        // 根據座標數量判斷形狀
        switch (coordinateCount)
        {
            case 2:
                return "Line";
            case 3:
                return "Triangle";
            case 4:
                return "Rectangle";
            case 5:
                return "Pentagon";
            default:
                return "Unknown";
        }
    }

    static double CalculateLinePerimeter(System.Collections.Generic.List<Tuple<double, double>> coordinates)
    {
        // 線段，只計算長度
        double perimeter = 0;

        for (int i = 0; i < coordinates.Count - 1; i++)
        {
            perimeter += CalculateDistance(coordinates[i], coordinates[i + 1]);
        }

        return perimeter;
    }

    static double CalculateTriangleArea(System.Collections.Generic.List<Tuple<double, double>> coordinates)
    {
        // 三角形，計算面積
        double area = 0;

        for (int i = 0; i < coordinates.Count; i++)
        {
            Tuple<double, double> current = coordinates[i];
            Tuple<double, double> next = coordinates[(i + 1) % coordinates.Count];

            area += (current.Item1 * next.Item2 - next.Item1 * current.Item2);
        }

        area = Math.Abs(area) / 2.0;
        return area;
    }

    static double CalculateRectangleArea(System.Collections.Generic.List<Tuple<double, double>> coordinates)
    {
        // 矩形，計算面積
        double area = 0;

        for (int i = 0; i < coordinates.Count; i++)
        {
            Tuple<double, double> current = coordinates[i];
            Tuple<double, double> next = coordinates[(i + 1) % coordinates.Count];

            area += current.Item1 * next.Item2 - next.Item1 * current.Item2;
        }

        area = Math.Abs(area) / 2.0;
        return area;
    }

    static double CalculatePentagonArea(System.Collections.Generic.List<Tuple<double, double>> coordinates)
    {
        // 五邊形，計算面積
        double area = 0;

        for (int i = 0; i < coordinates.Count; i++)
        {
            Tuple<double, double> current = coordinates[i];
            Tuple<double, double> next = coordinates[(i + 1) % coordinates.Count];

            area += current.Item1 * next.Item2 - next.Item1 * current.Item2;
        }

        area = Math.Abs(area) / 2.0;
        return area;
    }

    static double CalculateDistance(Tuple<double, double> point1, Tuple<double, double> point2)
    {
        // 計算兩點之間的距離
        return Math.Sqrt(Math.Pow(point2.Item1 - point1.Item1, 2) + Math.Pow(point2.Item2 - point1.Item2, 2));
    }

    static double CalculatePerimeter(System.Collections.Generic.List<Tuple<double, double>> coordinates)
    {
        // 計算多邊形的周長
        double perimeter = 0;

        for (int i = 0; i < coordinates.Count; i++)
        {
            Tuple<double, double> current = coordinates[i];
            Tuple<double, double> next = coordinates[(i + 1) % coordinates.Count];

            perimeter += CalculateDistance(current, next);
        }

        return perimeter;
    }
}