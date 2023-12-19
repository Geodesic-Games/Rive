// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class RiveLibrary : ModuleRules
{
	public RiveLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string RootPath = ModuleDirectory;
		
		if (Target.Platform.IsInGroup(UnrealPlatformGroup.Windows))
		{
			string LibPath = RootPath + "/Libraries/Windows";

			string LibFileName = "rive.lib";
			PublicAdditionalLibraries.Add(Path.Combine(LibPath, LibFileName));
		}
		
		string IncludePath = RootPath + "/Includes";
		PublicSystemIncludePaths.Add(IncludePath);
	}
}
