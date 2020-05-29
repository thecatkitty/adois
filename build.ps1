$Generators = @{
    nmake = "NMake Makefiles";
    wmake = "Watcom WMake"
}

$Projects = [ordered]@{
    dosadapt = "wmake";
    wizard = "wmake";
    compiler = "nmake"
}

$Projects.Keys | ForEach-Object {
    $ProjectName = $_
    $Generator = $Projects[$_]
    $GeneratorName = $generators[$Generator]
    cmake -G $GeneratorName -S $ProjectName -B build\$ProjectName
    Start-Process $Generator -WorkingDirectory build\$ProjectName -Wait -NoNewWindow
}
