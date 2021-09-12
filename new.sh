if [ $# -lt 2 ]; then
    echo "Syntax Error: Too Few Arguments.";
    exit 1;
fi

case $1 in
    AtCoder)
        mkdir "AtCoder/$2";
        cp AtCoder/AtCoder.cpp "AtCoder/$2/a.cpp";
        code "AtCoder/$2/a.cpp";
        ;;
    LeetCode)
        cp LeetCode/LeetCode.cpp "LeetCode/$2.cpp";
        sed -i "s/LeetCode/$2/" "LeetCode/$2.cpp";
        cp LeetCode/LeetCode.hpp "LeetCode/$2.hpp";
        code "LeetCode/$2.cpp";
        code "LeetCode/$2.hpp";
        ;;
    Rename)
        if [ $# -lt 3 ]; then
            echo "Syntax Error: Too Few Arguments.";
            exit 1;
        fi
        cp "LeetCode/$2.cpp" "LeetCode/$3.cpp";
        sed -i "s/$2/$3/" "LeetCode/$3.cpp";
        cp "LeetCode/$2.hpp" "LeetCode/$3.hpp";
        ;;
    *)
        echo "Value Error: Not supported OJ.";
        exit 1;
esac
