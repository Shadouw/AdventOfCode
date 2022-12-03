#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputT = {
    "vJrwpWtwJgWrhcsFMMfFFhFp",
    "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
    "PmmdzqPrVvPwwTWBwg",
    "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
    "ttgJtRGJQctTZtZT",
    "CrZsJsPPZsGzwwsLwLmpwMDw"};

const vector<string> inputA = {
    "LdHVLDLDdHdtLMhcqCqGWcWg",
    "ZZQZSZnnJrQrJQJbfzfnWGWPWMcChMMPcqMnhFcF",
    "ZrzpWzfbpQpWbzvZWZpdtVtDNmRHNVptNDHt",
    "gzCjffWZCtCfZZVdqVSqJdvJndSt",
    "hMHLcmGLMLhHmsRMsSvsQSqrsrlJTTdV",
    "NPNGRGHGHNLczNzzZFWSFFCC",
    "VSBpcvNNbNWWSfGRwtJnRtrzzGzGGn",
    "jZlhTlQLHFLLZbwrzQQsttDtbs",
    "hmmPFlhLmhLMgFMFLbMBBgcNVcfNCcfSVSSNBq",
    "jRDSzjCjjMRMrHzMRCDHMDjBnlQbbnQwLwrNLPwnTPQrlc",
    "sZBqdZqsWgFBpgppGJqllPllwnbQwTwsswQPwN",
    "gJgtJJBtqJqWBGzjRCHDDzRmDtVV",
    "GRBWbbWnGNhbwSsfPfmrlslWsS",
    "HLVCgCLpMgcLVDcDCgmlvstSlsstPtSSSlscvl",
    "LzQDQzMMzJzFQVDJgCzJHJZRZBNbqGFhNFwBGhbhBhBm",
    "JNsHhdPZSdZJjSHzzNwvwGgBFmBmvptJbFvm",
    "WrDrwqqqQWVMCvMvGbGbbFFbFp",
    "rqqLncqnlCncwQWCwWlLfSZPsZddfzzNNdhdPlZz",
    "rwfrwHqSdRcgwdZrDcrqDDdgNzjNjPzPJNJPtbNPbGsHNGHv",
    "hllLMTLLQMCzJssPsTvtFG",
    "QtQnpWVVMVWnVQpRZSSwZDggrcSq",
    "FDlqPMBdmbqMrdDqqFdFDwjHZChHHZfZWZNBsZjhfhHf",
    "VQJVgncpTQRJfsssGhsNWC",
    "NtpLLSpcLVRzzRRtpgVcLgglMwwlPlzdmDlFmFPDmqqwlF",
    "PqwwSqNWPqwSWqjNBwpTPpffhJfZfstRtZJRRdJsdR",
    "VFLFzQVgVnDVjhdJHsvhZjfg",
    "VVFVDDnmnzLFCzVmznFzrFlrjSCPNMBCSGSGwwwGBjPNWPwC",
    "zzbCGrfgbzfzCtvqdjSrvSjnvS",
    "cNVTLnJZRNNmQmhJNptvBlBtVjlljqqldtlB",
    "ZhpcJHLQhRcLZLmNQJzfFwDzzgHPFngDPPnP",
    "ttntdMMBZzbZZtjPfwjwTwBvvVmh",
    "llSllRRNsGCrCDTPfgVgTfgvsjPH",
    "CFclcCWGrJNDSnnWMbQTnWtLQd",
    "bccfdSfwFsswcbbdJFGQVGnCJLnBLnDnQLDj",
    "ThvHZNhZmqNWMNqvDVjcjjBQVhQBBVLB",
    "vWMZZNRmNMWqtWqmqHclfFgdlwRwrzzSfwbFRd",
    "WNzRWWZNmtNZnssNRPtCJFQJCffVJVffCvlF",
    "cBqBLgHHBcgqBbCJjrvrVQJfsHlr",
    "DhDShwchBSbdwBsqgGcbgTTRmzdNWmMRMmTdNpTMmW",
    "FHWZDbbPZDFHgGGPdPbJNLpJSlNjcjSphcJjFN",
    "ZCCrBBRwwCjcNwcljppN",
    "CmTTsrMfBCRsTMnnCRTmVZbgdbdGfWHPDVvdbbPV",
    "cgSNBScMgjBBPtBCNLVvVVvhhJJhvsMhVfWq",
    "TFlDrHPZHTTFmwTQHZDZTrqvvzqlJppVJvpffhqqVfJp",
    "DbPwrTZDQDRQQwQZrDrbbQwRRnNSBtCjtcNGjSgSLjLccC",
    "pdcVCpdZnZgcZgdcDWBDNcNwvBWJwc",
    "RRmHspRmmQfLwwJJbFBFFJNR",
    "rGlpfrQrqGhGqdGP",
    "THhNsHhdFjcDthDcjDhLBqWcLLQQJvvBbvBJbl",
    "GfrCSZGCzfVMrVCCzGVfSMQBBFlJlJBFFZqvWBqbbQWl",
    "rSrFwCwzMMzRfGrGMwPfGCVdgHDttthNPssHjmNNdDjgdD",
    "shmhggDsZCZWBDmsQTcTqrLPTbNbwQQrrN",
    "lzpFVfdjfFFGnVVHpjJGJVlprNMPNtPctTNwLtcTbwctwTnN",
    "jVFfzVlFSpzpFCshWmgSRgmBRb",
    "zZGFNPmdPdszdWddGWZlpLMLpbQbLDpblzQbtv",
    "wTwgwSSCHhhCSghJbpcpDglbbQbMVMpV",
    "BHnBRrJCHmRNfGDmfm",
    "CffgvfCRGngRrvGvgdnRVpPQQPSqbVZZDPDVPzFSSQ",
    "cMlWJTMlcTLTLtHHJlpqDLwqSzSSDDqDZDDS",
    "tmHTtlMmWpmsMJsCRdCNsrRGfrnffN",
    "lNrzNHNwzZlHmwNBpMqqnqGDZSpMTGnb",
    "ddjgFjjsRvGvQhQvvFjqbVTFpbVpFDJSbJVpTS",
    "cjsQhsjvRvGcgNtzczmtmwCCcr",
    "NJMJvBmBJPtMtRDnDDwDMFFWDWHG",
    "hZsrzshpSdjZZqSSfgpDwnwFnGCCLHDbjnGCWG",
    "zfgSpScsrdpmllttGvJGcm",
    "GLsnLVLZGZmcGVpgZLmTjTsDDTlDTHPPHWlHwD",
    "dNJhCCdtNJSvdDzwPlvTlQ",
    "BCbBrPPfRMfMJSffrMCMChrSqVcmLLFpqLFFcggLVnqgmbgc",
    "hMdjMndZLRnRnjclszLclQlzGwcr",
    "FPCCSCSpCwStJVGzsPQGslGzPbsQ",
    "TSSJTtfTFTwtmTFFVFDTWRvdgndjjRhnjnvHjdfR",
    "ZwgsnsWsWvWQHqJhGhJVCJHhCJ",
    "cdjlMWRRMhJLCpLL",
    "jjSRmRmNRNWBmdmcWjlDWFPswsPtnZQsnBsnZvvTTnvT",
    "vvbjLTPbQzrQQjpLzLbflfjfRDDsDlRfgDnnVD",
    "ZGCtHHFGzFHhMlCnDqwlgggsqf",
    "FJHMhHZGmNHtJhMhBJZZtZdrbSbSzbmWLLQrQTbPdbrS",
    "ZClGVCvLZzCLBVbdGGzVVBvVrqQMDWMHrgmgQLWrWmTgqqHH",
    "tNpNspcQPfHmqfgHmHHg",
    "nNttnwPRjFtPcccsFptPlllQGlQZbvGzVVVFzhCd",
    "lflmVWpDVsMmmVPlHVbbGSSbGnSHJcncnLZn",
    "NvTFzNwzTQvhFGSZnvgrbgJCgr",
    "jtRwTQFzjBNGGQQBdDsDqqlsVqRflMlPsP",
    "rCSJPCrBwwMdBJRCrwMTGWTWNbcjGZNGGZTb",
    "qzgqfgFghsHzfgHgmmfWGNGGWcNNFClbWlcCNW",
    "DqsnzsHLhddBDwCRJR",
    "sZpHjZrVQmcrbhbthzhFHzhH",
    "QDPMDMndqqQGqQfCDDbhFtzzLtbWzlBLLPBW",
    "TDMDqfGnJSnfnfvgjsjNgJvsjVQv",
    "bDZQbZHdQQggZfttJjGnplSnldsG",
    "FTrFCvWBWzTNSPNvRBGJsGjpsJjstmCLtjCt",
    "rhBvzRVRBBSVHDHcHMHq",
    "FSbSNZbZbzGzGGbNzGgcZPwlDPvlNmLLLwLLlLvvvl",
    "pqnqpVCrpshqmChsQnnRpRCldDHvDHLjDlvPwddlwPtwDV",
    "rRTCnnpCWCChTrWsrBTfbcFFmFSSmfBBGg",
    "QdhdWDsHhHWzPrLPSCPGvs",
    "gpZZmNmtjZwpBZBZgSnvFcGPrrvmncnvmC",
    "RVVRjZJfJVfVBZVtBNBVppZVDqMHhqTbMGlWHQhhWldRMHWd",
    "BPWQrRRNNMhrHhLqqGgjDJjH",
    "TzVmmpmtCNwscTzszcNzDCfCHJqDfGjDJJgfGCDq",
    "wdwmspTsVdlTcpbmVMPWBbBWRPNnFnBWMr",
    "VZTnVnsgrjjsqPzPwWgWPghz",
    "mcFdQGPMBdMSBdWbhRzzWqwLwcWt",
    "GQPBvpfvNvFPBvTnfjnZDHDDjsrr",
    "CZssCNFJBmBNFmFBNwBFCJFTtthGrrSThtSgSRtSfRTGtRrg",
    "LDpDbnjjDGpggGrvGg",
    "PLMWnWQgbQWnWbnbjqDbszHwwzwmNsFZMBmwJFZF",
    "hQSjFLhFLLMSSFgdWTMdGgNbNbWv",
    "JmPlltJBJqmzpbrrwTwrvvGqww",
    "HBzztRBRplzlmHmRmmsplRJZcfFcLFfHSLjSZTcfVVcLVH",
    "nBSQMnVQqJBGnfVfDgCrjbVbtC",
    "FNcPPHdTdhmBdHBvwlZjbClClfcZgjclgj",
    "vFdHWhTLHvnBRRqBsWSR",
    "TRsNNTTHRRZRRsRzJQddSpJLcQdpjs",
    "DMVPVVGmMGWMGtMgGtDlmMWwLLLpJfSfpjzpdQddLSmSSJdc",
    "tVMgGMDwMgMWDBWMttjRBZNnvNCNZrZZRbZNvZ",
    "wlJPVMJPPBShSlhgfTvgNNzzgNMCTg",
    "FLtRnDDSrvdNdrng",
    "FcSmpFZFFmmjWqPWJbmhGqqm",
    "hlBqqTlSfvNhpbfb",
    "fRVsVDDRtnRVfbDNCCNCNQGwNZ",
    "nrrRPPnHzntRrPsRVrtJVBMjlzWfFWdMjjWMqdBBlT",
    "zDNcnRsNNfRFFNNzRzLbRWgMZMMZcdhcBdMrBpZmmZ",
    "PVHHVlPDGPPtjDmmdrrGBBMpWGWd",
    "VVqTTlQtDCqFNzsnbLbCSJ",
    "ndSGSZZGwSZTBdwnwdwmWCzPQCQLffZzRgMZRggMzf",
    "mvqVmqrmcDqllNNtbcNcMCQMRCMCCMQfHLgvRgMg",
    "FhNNcrrVljFcqmTJhwnsmGdJsT",
    "wlmLmZLwzvVmVWVmQWzZSFJFDSqFHSSFJHhDqZ",
    "RsgpMNcMdRgjDcRFqCSrHSHBCFJr",
    "jdncssDNPsbmmwvvlPLw",
    "wQGHMrHGgwgVTQrrMGgGQrTtWzzPJhsfhZztWssQWbZCWh",
    "FjvBFSqqDbljFvSbnvFltszfWPPfWzJZBCsPtJft",
    "qLlDbpjFRbpdGTgLGLGTTV",
    "hrVJsBrpwbsMZtTLlwnqtqdc",
    "QDDmHWmffHCQWHjRQjCWczTTjtlzdldqVtTnTqLt",
    "HmfGfRNWfNWmQCRsgbsMFMhMGvpBVs",
    "CRzzVCZhvGQqNmcWrgpgwQFSmF",
    "BJsttjDtjbdLMHHsBTqBbBHMrprDSrFnFnSgrnnrpDSmWWnw",
    "TbMBMPPdLTbHTjHMtPzZGvzlvqCPGNlNVRVP",
    "QcmcrCVcdTCGRRLT",
    "zzgWFWVBTSWLPdMP",
    "JbhnBVzzfVhgztVDvqcqHwncZHNqnsnccQ",
    "JJVBFfJjNNNsJTwVfZJNffFRpRzRzRptRWtCtSSHWsWzCD",
    "rmrnhgclhQGcGnhrPjqgGMHbWRHRbRCWbzRbMSSpHWCD",
    "mhhjQGGjQgggqnmQnmghdQdJFZBNvZBBLNTvvTNNTLfZ",
    "DrBgwMCMRvMrvDgPCzdpdNtzqqlHNNtp",
    "jWSSZGgfGjcLfdNjFzqqFFzzFF",
    "nGZhTmZLLZhGPVVTgQgMRrrb",
    "ppqZvppdJmSLHdSfZRrrtbscgRVVgwVrHt",
    "hFFFzQPhNWzNhnhGVggrcbwVgBnvbwgR",
    "CNQWFMzWWhCflpjvZJMJdj",
    "pfpfmQMWmcBVfMBBmpfVQMbDGGNPDTcSNTTsSNPCCNhC",
    "ZZrZwvvzZrvZlZlwhwswhNSsgbDssC",
    "ttvdtzRzFDqRJWLVLWJJpQ",
    "CZZPTQPTPTJhTQTrHCBbvtLbbbRWtjbDvb",
    "cGfsVSVcLdSgSwBWRNNGwRNRbD",
    "spSffnccsgcdnnJJQlZZqJLhpMJh",
    "TwGGdWwdddtTsbzPzbbnTLnPLP",
    "gqNSMvtvcSDLLfnMnnPzFM",
    "NvDNDqtvRcjQVGZZGZZhwpQB",
    "jtgFmnqjqttQpsphzNllblzlNH",
    "GRMRDMGCVCHzSCbSbNNl",
    "LMTJRTGRLBJBwLRRHmBFQPvqmPBvtgtc",
    "jDjjwRDpPqqsMsDLJbJzVB",
    "lMNMNddvMltNfFVWbVVWJrrVLfgL",
    "NQQtmtFGFlGZPZcMmmcjjn",
    "CgCNjvSCgSQQzVZNWVnTBPTcsTVBnpPs",
    "bFbbLfbfdRBFhLwqFmblBJfRHtWcttcttlDpspcPWDcDptPn",
    "mdbFhfJrmJwfbmmFFFvBZCNCzMGrNjMQjCCZ",
    "TPDNHHSTNNmRfTrRMZSqwwttdbBvBMth",
    "VVnnFGgnQcBvMqvnhNBN",
    "GLzjjzGscssJGJCHljmfmTWPTCDN",
    "BZZNcMQjBNjNtDJgstjgtwqGRQfhGhSvPfThfqvPhfhf",
    "CCndrnmnnWbrnHrFbWbpbbVmGGPqLfTGhvGSPhqRLRdfSGsf",
    "bFssVbbblFHzrmFlMNMtcNgDtJDzZgtw",
    "smjMtSqQQSjtSfmDVVFHFhnHBHmbNPPH",
    "TgvCCJcZdwdgNvbHvPbbvBNq",
    "JLqRWTgLqJLCJcclgCJdWjfsSSpsfRrsQjDtspptQQ",
    "hNwztzgzJnnNTVFwNTNhwVhZlrpLMLZZlpZlQndLPLpQLZ",
    "vRDvqSSqjbqSWDvjbvBdLWspPLddZPQQLMllLp",
    "SfGfRmSGCSfBfjTcNFgzwMFJzwgm",
    "lhVBhZjjPHbThwFGrNrdvNNwFV",
    "DRrDLfMLSgpCdCJcfmcJCm",
    "LQtnprtqSRtZjHzTthlb",
    "GrGsqfbtsWGWWntnrrwWWWGSSDSMDcSSSwTDzPzJSJzPcT",
    "lmQhhVCgmffCNgmNNmCmBNRRPvDzDMhJvSSDJzzcTzvvPvMT",
    "VBllNBpfQgQmpLBpRBtnqWLFFnZZWWGrZrjq",
    "NRJdngMVwfgnwJtvlblcWLlLDHfccDbW",
    "PFJzBmhmjPFpJrFqLcQHLlHGDlHDQbGz",
    "ShJZJmPFpwdMvCCZRd",
    "WQDqSVWqpBCsPqPWWNscfrHfhrhrHhGFGs",
    "MmLRmLTjmTzTzlhGHfprhvfFhHfT",
    "mLZLRdgMRjtdddmdgwmtMwQSCPbnDSSCqBDwpWPQqn",
    "rNHwMMGDrggWwsvWMPMWWwjbCqjCBlZqvfjBqCJhfffj",
    "FbtFmRTpzBBZqCClpJ",
    "ztbzFtnzVNnNNPPDGD",
    "PLPFcwdLdFcbgdfSwFtWhGWGRMWMJMGCblJR",
    "qTpszVVjRlCHtWCT",
    "qzvrDqQrqznzggFZwFwQScdW",
    "LWLjLNjNjTwlwLZVcBVcVVZcBVQcZZ",
    "JhGhFdmBRdGGDnQtbPvVVdnccS",
    "zDrrFGFFRgRHmDNWTpjTBNTHWNjW",
    "fwfBVLhmwfhHsgBstWCWQnDQnlldWW",
    "hZvFTNJrZjZbFvNvttqWWDtcWqCtFDWn",
    "rbjjrjpRzRzgBLzwLgmzLh",
    "ZqqqWVzdSPnwBJBfwJfZTs",
    "FHGgjRLMJFsJTsBw",
    "DHRcDgHvLhDWPSCzwqnq",
    "LZGZLLRLZpRQBtPTjTffrHljjmsB",
    "wNVVwcCgNCCScwggmjHjTPmQPsTHmlSs",
    "gbbwbqhNCQcbqqVchWhtRZDJWJDtZLWL",
    "CmTmvvmvzCCCgzzVQmTQvTjjGRGShwSHwRrRSSSSDNHSFN",
    "PqZqWdqlplsqBJMMsMMnGRJRbbNwNhrrhShGShFD",
    "fBWBWdZppqpqDMBdlfcTCTLtLtLCQfQvcmgv",
    "pntdtdHHWHqnptGpqHqNgMQwPPPnZMZZZZcfgc",
    "LFmLSVBRTSBBRrffTQgMfQMtJZQT",
    "bmRCSSSjRCtSrRChjqqGqpppGhqDGp",
    "dGGhhfNfgRTGLcpL",
    "BmCCwQMQqmQrBCBJLpbVTFbHcgcbLTMc",
    "JrpqJJmqqqqmzqqwmwNlzfvltDPltfshlhNN",
    "VCCbMJfJlgRCnNGVNnvFvVBF",
    "STsgcZdghZsqSttBnsGnBtBtHt",
    "qDcjgDphjhSghZTQgCJWQWWfwfRzWlwJzJ",
    "JHMVMvmvRcdbmrRHQBBGjcjfFQfChSfj",
    "NltNtZllgZtgtnpnqNWpgCrCBQzBGzFhQrGSSBCzWh",
    "pDrwnqLlvDVmPbss",
    "dbrpbSrwBjswsSjCwqllLqFtqLcrGqqFtF",
    "RvfJDQnRpHvvQfRvvQRJFDqzcWltFFlzcLttWltW",
    "ZpnRVZHmvHnTnPZZPHfHmVwdjVghwgVSBgdBBCwgdC",
    "WRCBGWvNgHnMcFwnpC",
    "ltlstrjlJNlfrZZqDJtNLsHnmwwpcHphhFPMFjwhmnFp",
    "TStJssLstJLtqTsNgvvSBNzzvWvGRz",
    "VBjdWdGcqWdBVCFRmHwfCRRV",
    "DLzNpqbDzDNbrJvltMLJLRRmtRFTSRmTmFwfRHRTFf",
    "zvvJNLgNqGcnjgnP",
    "JjdnFfbdbdQMbQzjtRcwcCvbvBqRBCwt",
    "LlNHlWGprPCVVBsVzqNR",
    "hLmgTlrpPPHrLprHrTTGggHWzhZFSJDfhMdnjjZfFfdFMjFz",
    "bDbwRpCSRgqqMfMf",
    "HzzPcPnhzlhsQzHhHnTggBBqTQTgVQqBqjZW",
    "tnsrFccnzsDvGpNGqNtq",
    "GmPsPrsSlswNmcLzMvnpnmMpLBCf",
    "glDTZRDqRTjRCvjvfBpfCzvp",
    "DHlJVhJRDTbqZDqSNVrNwtVrQwSSGs",
    "nNnDwqDwFVgDwDnCgLnLpCVWdBMRpsPdMPPjRHRHHRdBWj",
    "tQtfTtJtJmlTQrTtTlhfzrmdHzMMRMsBPPddjddBPPdWsB",
    "bbhtQTfTTsmmbStnqGFGNDbFDgFVnw",
    "dsVpDPBMHVdHpplpvdHjRjmmjRTMTFFrrTTFQq",
    "LzzWZLGCzCWNjfmRfBhmQjZq",
    "zSSSwJwSBzNtzLBbwbSGLzWVvcvpHdssDllVJgVHVcdDPv",
    "RWfQBDTBLQWpDLNRZjZwHHddjHNhZdtv",
    "ScCCzSszFzJccPHHvmjHvjhpmHsj",
    "FPclgFVCbcngVgnpWQqqRfLBDBrR",
    "cRLLVwcsctwmbVcszztwtRMvNrCpTggqFrTvvhCVpghBqh",
    "PdSDGdnZQfGDfDjWjWWgvCqFhpqvpNZgCTTvrp",
    "dGnDHWnSQdJPDSFLLcJmRzzLLLRRcl",
    "lCSqlcCcBqBCCwGwnNWnnFwBHF",
    "WMZLMPbPhQddRbMpbbLbRLLHDFgjFGDmFNZgNnDGNHGGjD",
    "dTVPPQbPbMdQMzvVrWvczrCJqv",
    "vzscdHcHZzHzCCHlQTTTCcslMGPStmSlpDDSSSgSPDNBmNtl",
    "FWVMFhFMMqWhFVFbDBDDhpmpGtPSDpGG",
    "fRLbFfwWWLnVjMdzzQHQJnnvQs",
    "SmPdRbWZdSqqzSPmbdWFFQgcQnvncgQGQMMT",
    "BfBLmVNjprVVNlVBrpBlHpNrgQFHGCGgvTQTMGFFgMCvgQcQ",
    "BjjJfVLBfNffJbZDqtDsdzzm",
    "NLgtLsSggjqgqpLLDjsjmcJfvpmFmmJmvPpwhBJB",
    "lMnlZMtdCMrRRnRbTddWbVwcmPfFmhJwPfwJmvfwFvPl",
    "MnRrnGWRbgQqtNGDjt",
    "dSdrTbTtLJCcttcFVw",
    "PhsgQQGPZshvpQZGgsrBllVFlHVpFllJJrFH",
    "gqsGPgMZhgvQbzrzTfSzMTLf",
    "pqbDdQWqCgBfbbfFfB",
    "vtjnmzLcmhBdzTFgTsRP",
    "LZGmjvJGGctnLtvcchSjmhcLqNHCwVdQZwDwWDNpCwqHdDwQ",
    "wlMWSSHWShSMbDSwVhCrNjJmcrDmGRRCGCjN",
    "FHZdHftFFQnqsQqsQttjvGrJccmdGGcrNdRNmG",
    "pHpzPpQHpsPzPlzlbSgSSMLwzh",
    "fCQDLlDQTSjbHDqH",
    "ZhrsrZZZhcclwNswGGwbwF",
    "rcWhlhlpMJpMZmgtBCzCttCCRfdp",
    "zLnCMLNTvtGNpNvNjhRHgZhHvZdZHdjD",
    "fSsWWqScTfJJqfJFFJwswhdHhhhdhDdjbjZbhhDj",
    "WsWmfcqBWfTfsrntrLmplCLttm",
    "ljssbqMMPbHPlsbcWZNLLsWJWRFvvZfW",
    "SzgggDDwTzrQmDQgdSSWvdJLFGffRvZG",
    "zCzCDCrznnTTmCbbpvlPHtCPtb",
    "TZSwNPpcgpNPbwbhhbwrwJqh",
    "BlCDtvvgLWGCLffGfLzLrMqnnbDDHbmnnnJrhnVJ",
    "lzBjdCjCGCjfGjjLGBGGjlCSsRppcdpRNdRSPQcRPQZTgT",
    "TsFTrvGmZGfvZfZFzNNZrhClmRcBgCMwQwQPCPMPRP",
    "bpnnVVJtSDgRBwbQRwlR",
    "jpSnqLpqDJDJLDjWDWLWvvzfZZvqvNsGTHGGFfZl",
    "bzbzznqfCpzvhCSMfbCbpCFhtHGHHJdtHJGhFsmshJJG",
    "DLWRLjRrmNPQjZZlQPsFGFggVcWcFddggdsg",
    "rjrZPwwDRlLLBjQlRRlPDpmbqzpqnnCSCfTMwMqSvC",
    "FmcGcjLRPjQwQjMQrwHQ",
    "btJzJbVNdBJJtzTdGBbdBztGrQhhQWhMwHrhrHSHgHQfhMVS",
    "JJDpdDTtCtzNptnTJBznnvLCCvcFqsRqFcvZclLGRR"};

const vector<string> inputB = {
    ""};

class Rucksack
{
public:
    Rucksack(const string _input) : input ( _input )
    {
        leftcompartment = input.substr(0, input.length() / 2);
        rightcompartment = input.substr(input.length() / 2);
    }

    char getMatchingCharacter()
    {
        if (0 == matchingcharacter)
            for (auto el : leftcompartment)
                for (auto er : rightcompartment)
                    if (el == er)
                    {
                        matchingcharacter = el;
                        break;
                    }

        return matchingcharacter;
    }

    int getPriority()
    {
        return getPriority(getMatchingCharacter());
    }

    static int getPriority(char mc)
    {
        if ('a' <= mc && mc <= 'z')
            return mc + 1 - 'a';

        return mc + 27 - 'A';
    }

    string getString()
    {
        return input;
    }
    void setBatch(char _batch)
    {
        batch = _batch;
    }
    char getBatch()
    {
        return batch;
    }

private:
    string input;
    string leftcompartment;
    string rightcompartment;
    char matchingcharacter = 0;
    char batch = 0;
};

class RucksackReorganization
{
public:
    RucksackReorganization(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            rucksacks.push_back(Rucksack(elem));
    }

    int getSumOfPriority()
    {
        int retval = 0;

        for (auto elem : rucksacks)
            retval += elem.getPriority();

        return retval;
    }

    void batchRucksacks ()
    {
        for (auto rs1 = rucksacks.begin(); rs1 != rucksacks.end(); rs1+=3 )
        {
            auto rs2 = rs1 + 1;
            auto rs3 = rs2 + 1;

            for ( auto c1 : rs1->getString() )
                for (auto c2 : rs2->getString())
                if ( c1 == c2 )
                    for (auto c3 : rs3->getString())
                        if (c1 == c3)
                        {
                            rs1->setBatch(c1);
                            rs2->setBatch(c2);
                            rs3->setBatch(c3);
                            break;
                        }
        }
    }

    int getBatchPriority()
    {
        int ret = 0;

        for (auto rs1 = rucksacks.begin(); rs1 != rucksacks.end(); rs1 += 3)
            ret += Rucksack::getPriority(rs1->getBatch());

        return ret;
    }

private:
    const vector<string> input;
    vector<Rucksack> rucksacks;
};

TEST_CASE("Testdata")
{
    RucksackReorganization testRucksackReorganization(inputT);

    Rucksack rs1("vJrwpWtwJgWrhcsFMMfFFhFp");
    REQUIRE('p' == rs1.getMatchingCharacter());
    REQUIRE(16 == rs1.getPriority());

    Rucksack rs2("jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL");
    REQUIRE('L' == rs2.getMatchingCharacter());
    REQUIRE(38 == rs2.getPriority());

    Rucksack rs3("PmmdzqPrVvPwwTWBwg");
    REQUIRE('P' == rs3.getMatchingCharacter());
    REQUIRE(42 == rs3.getPriority());

    Rucksack rs4("wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn");
    REQUIRE('v' == rs4.getMatchingCharacter());
    REQUIRE(22 == rs4.getPriority());

    Rucksack rs5("ttgJtRGJQctTZtZT");
    REQUIRE('t' == rs5.getMatchingCharacter());
    REQUIRE(20 == rs5.getPriority());

    Rucksack rs6("CrZsJsPPZsGzwwsLwLmpwMDw");
    REQUIRE('s' == rs6.getMatchingCharacter());
    REQUIRE(19 == rs6.getPriority());

    REQUIRE(157 == testRucksackReorganization.getSumOfPriority());

    testRucksackReorganization.batchRucksacks();
    REQUIRE(70 == testRucksackReorganization.getBatchPriority());
}

TEST_CASE("Problem")
{
    RucksackReorganization testRucksackReorganization(inputA);
    REQUIRE(8072== testRucksackReorganization.getSumOfPriority()); // A

    testRucksackReorganization.batchRucksacks();
    REQUIRE(2567 == testRucksackReorganization.getBatchPriority()); // B
}