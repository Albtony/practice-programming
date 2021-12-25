function sumTwoSmallestNumbers(numbers) {
    var min1 = Number.MAX_SAFE_INTEGER;
    var min2 = Number.MAX_SAFE_INTEGER;

    for (var i = 0; i < numbers.length; i++)
        if (min1 > numbers[i])
            min1 = numbers[i];

    for (var i = 0; i < numbers.length; i++)
        if (min2 > numbers[i] && numbers[i] >= min1)
            min2 = numbers[i];

    return min1 + min2;
}

const arr = [2,2,2,2,2];
console.log(sumTwoSmallestNumbers(arr));